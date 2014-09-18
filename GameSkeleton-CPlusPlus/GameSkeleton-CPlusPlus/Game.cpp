#include "Game.h"
#include <iostream>
#include <Windows.h>
using namespace std;


Game::Game(void)
{	
}

Game::~Game(void)
{
}

void gameLoop() {
	double TARGET_FPS = 60;
	double OPTIMAL_TIME = 1000 / TARGET_FPS;

	LARGE_INTEGER frequency;        // ticks per second
	LARGE_INTEGER previousTime, currentTime;           // ticks
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&previousTime);

	double lastLoopTime = previousTime.QuadPart * 1000.0 / frequency.QuadPart;

	long lastFpsTime = 0;
	int fps = 0;

	while (true) {
		QueryPerformanceCounter(&currentTime);
		double updateLength = (currentTime.QuadPart - previousTime.QuadPart) * 1000.0 / frequency.QuadPart;
		previousTime = currentTime;
		double delta = updateLength / OPTIMAL_TIME;

		lastFpsTime += updateLength * 1000.0;
		fps++;

		cout << lastFpsTime << "\n";

		if (lastFpsTime >= 1000) {
			lastFpsTime = 0;
			fps = 0;
		}

		//QueryPerformanceCounter(&previousTime);
	}
}


void main() {
	gameLoop();
	cout << "HOI";
	cin.get();
}

