#include "rlutilJM.h"
#include "Entity.h"
#include <chrono>
#include <mutex>


int rlUtilJM::SCREEN_SIZE_WIDTH;
int rlUtilJM::SCREEN_SIZE_HEIGHT;
Tile** rlUtilJM::screenBuffer;
Tile** rlUtilJM::lastScreenBuffer;
sf::Music rlUtilJM::music;
sf::SoundBuffer rlUtilJM::soundBuffer;
sf::Sound rlUtilJM::sound;
CONSOLE_FONT_INFOEX rlUtilJM::savedFont;
std::queue<std::function<void()>> rlUtilJM::delegator;
std::thread rlUtilJM::drawThread;
std::mutex rlUtilJM::m;
Entity *rlUtilJM::emptyEntity;
PCONSOLE_SCREEN_BUFFER_INFO info = new CONSOLE_SCREEN_BUFFER_INFO;

void rlUtilJM::KeepScreenSize()
{

	HWND wnd = GetConsoleWindow();
	HANDLE consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	m.lock();
		GetConsoleScreenBufferInfo(consoleOutput, info);
		if (info->dwSize.X != SCREEN_SIZE_WIDTH || info->dwSize.Y != SCREEN_SIZE_HEIGHT)
		{
			std::string mod = "MODE CON COLS=" + std::to_string(SCREEN_SIZE_WIDTH) + " LINES=" + std::to_string(SCREEN_SIZE_HEIGHT);
			std::system(mod.c_str());
		}
	m.unlock();
	hidecursor();
}

void rlUtilJM::WindowSize(int _x, int _y)
{
	cls();
	SCREEN_SIZE_HEIGHT = _y;
	SCREEN_SIZE_WIDTH = _x;

	std::string mod = "MODE CON COLS=" + std::to_string(SCREEN_SIZE_WIDTH) + " LINES=" + std::to_string(SCREEN_SIZE_HEIGHT);
	std::system(mod.c_str());
	saveDefaultColor();
	FontSize();
	CreateFakeScreenBuffer();
	{
		HWND wnd = GetConsoleWindow();
		HANDLE consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD coord;
		coord.X = _x / 10;
		coord.Y = _y / 20;
		SetConsoleScreenBufferSize(consoleOutput, coord);
		MoveWindow(wnd, 0, 0, _x - 1, _y - 1, FALSE);
	}
	KeepScreenSize();
	hidecursor();
}

void rlUtilJM::PlayMusicBackground(char * _musicPath, BOOL _loop, float _vol, BOOL _stopCurrentAudio)
{
	if (!music.openFromFile(_musicPath))
		return;
	if (_loop == TRUE)
		music.setLoop(true);
	if (_stopCurrentAudio == TRUE)
	{
		music.stop();
	}
	if (music.getStatus() != sf::Music::Playing)
	{
		music.setVolume(_vol);
		music.play();
	}
}

void rlUtilJM::PlaySoundEffect(char * _musicPath, float _vol)
{
	if (!soundBuffer.loadFromFile(_musicPath))
		return;
	sound.setBuffer(soundBuffer);
	sound.setVolume(_vol);
	sound.play();
}

void rlUtilJM::ChangeBackgroundVolume(float _vol)
{
	if (_vol == music.getVolume())
		return;
	music.setVolume(_vol);
}

float rlUtilJM::GetBackgroundVolume()
{
	return music.getVolume();
}

void rlUtilJM::PauseBackgroundMusic()
{
	if (music.getStatus() == music.Stopped)
		return;
	music.pause();
}

void rlUtilJM::UnPauseBackgroundMusic()
{
	if (music.getStatus() == music.Playing)
		return;
	music.play();
}

bool rlUtilJM::BackgroundMusicIsPlaying()
{
	return music.getStatus() == music.Playing;
}

bool rlUtilJM::BackgroundMusicIsPaused()
{
	return music.getStatus() == music.Paused;
}

void rlUtilJM::FontSize()
{
	HANDLE consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX currFont;
	GetCurrentConsoleFontEx(consoleOutput, FALSE, &savedFont);
	currFont.cbSize = sizeof currFont;
	currFont.nFont = 0;
	currFont.dwFontSize.X = 8;
	currFont.dwFontSize.Y = 8;
	currFont.FontFamily = FF_DONTCARE;
	currFont.FontWeight = FW_NORMAL;
	wcscpy_s(currFont.FaceName, L"Terminal");
	SetCurrentConsoleFontEx(consoleOutput, FALSE, &currFont);
}

void rlUtilJM::AddToBuffer(int _colorVal, int _backVal, char _letVal, int posx, int posy, int ocup, Entity* entity)
{
	screenBuffer[posy][posx].setBackground(_backVal);
	screenBuffer[posy][posx].setColor(_colorVal);
	screenBuffer[posy][posx].setChar(_letVal);
	screenBuffer[posy][posx].setOcupant(ocup);
	screenBuffer[posy][posx].setEntity(entity);
}

void rlUtilJM::ClearBuffer()
{
	rlutil::resetColor();
	int i, j;
	for (i = 0; i < SCREEN_SIZE_HEIGHT; ++i)
	{
		for (j = 0; j < SCREEN_SIZE_WIDTH; ++j)
		{
			screenBuffer[i][j].setBackground(0);
			screenBuffer[i][j].setColor(0);
			screenBuffer[i][j].setChar('\0');
			screenBuffer[i][j].setOcupant(EMPTY);
			screenBuffer[i][j].setEntity(emptyEntity);
		}
	}
}

void rlUtilJM::RestoreFont()
{
	rlutil::resetColor();
	HANDLE consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetCurrentConsoleFontEx(consoleOutput, FALSE, &savedFont);
}

void rlUtilJM::PrintBuffer()
{
	for (int i = 0; i < SCREEN_SIZE_HEIGHT; ++i)
	{
		for (int j = 0; j < SCREEN_SIZE_WIDTH; ++j)
		{
			if (screenBuffer[i][j].getOcupant() != lastScreenBuffer[i][j].getOcupant() &&
				screenBuffer[i][j].getOcupant() != EMPTY &&
				screenBuffer[i][j].getOcupant() != BAR && lastScreenBuffer[i][j].getEntity() != emptyEntity)
			{
				setEventCollisionStatus(true, lastScreenBuffer[i][j].getEntity(), screenBuffer[i][j].getEntity());
				setEventCollisionStatus(true, screenBuffer[i][j].getEntity(), lastScreenBuffer[i][j].getEntity());
			}
			if (screenBuffer[i][j].getBackground() != lastScreenBuffer[i][j].getBackground() ||
				screenBuffer[i][j].getColor() != lastScreenBuffer[i][j].getColor() ||
				screenBuffer[i][j].getLetter() != lastScreenBuffer[i][j].getLetter())
			{
				locate(j, i);
				setColor(screenBuffer[i][j].getColor());
				setBackgroundColor(screenBuffer[i][j].getBackground());
				std::cout << screenBuffer[i][j].getLetter();
			}
			lastScreenBuffer[i][j].setBackground(screenBuffer[i][j].getBackground());
			lastScreenBuffer[i][j].setColor(screenBuffer[i][j].getColor());
			lastScreenBuffer[i][j].setChar(screenBuffer[i][j].getLetter());
			lastScreenBuffer[i][j].setOcupant(screenBuffer[i][j].getOcupant());
		}
	}

	ClearBuffer();
}

void rlUtilJM::CreateFakeScreenBuffer()
{
	emptyEntity = new Entity();
	screenBuffer = new Tile*[SCREEN_SIZE_HEIGHT];
	lastScreenBuffer = new Tile*[SCREEN_SIZE_HEIGHT];
	for (int i = 0; i < SCREEN_SIZE_HEIGHT; ++i)
	{
		screenBuffer[i] = new Tile[SCREEN_SIZE_WIDTH];
		lastScreenBuffer[i] = new Tile[SCREEN_SIZE_WIDTH];
	}
	for (int i = 0; i < SCREEN_SIZE_HEIGHT; ++i)
	{
		for (int j = 0; j < SCREEN_SIZE_WIDTH; ++j)
		{
			screenBuffer[i][j].setEntity(emptyEntity);
			lastScreenBuffer[i][j].setEntity(emptyEntity);
			lastScreenBuffer[i][j].setBackground(screenBuffer[i][j].getBackground());
			lastScreenBuffer[i][j].setColor(screenBuffer[i][j].getColor());
			lastScreenBuffer[i][j].setChar(screenBuffer[i][j].getLetter());
		}
	}
}

void rlUtilJM::TextWrapper(const char * text, int color, int background, int posx, int posy)
{
	std::string a(text);
	for (int i = 0; i < a.size(); ++i)
	{
		AddToBuffer(color, background, a[i], posx + i, posy, TEXT, nullptr);
	}
}

void rlUtilJM::AddPixel(int y, int x, int content, int **& _sprite)
{
	_sprite[y][x] = content;
}

int ** rlUtilJM::InitSpriteArray(int y, int x)
{
	int** arr;
	arr = new int*[y];
	for (int i = 0; i <x; ++i)
	{
		arr[i] = new int[x];
	}
	return arr;
}

void rlUtilJM::AddToDrawThread(std::function<void()> funct)
{
	m.lock();
		delegator.push(funct);
	m.unlock();

}

void rlUtilJM::setEventCollisionStatus(bool _status, Entity * collisioned, Entity * other)
{
	collisioned->SetCollisionState(_status, other); 
}

void rlUtilJM::executeDraw()
{

	while (1)
	{
		if (delegator.size() <= 0)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(16));
			continue;
		}
		m.lock();
			std::function<void()> f = delegator.front();
			delegator.pop();
		m.unlock();
		f();
	}
}

void rlUtilJM::startDrawThread(std::function<void()> funct)
{
	drawThread = std::thread(funct);
	drawThread.detach();
}
