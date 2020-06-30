#pragma once
#pragma once
#include "Window.h"
#include "Timer.h"

class App
{
public:
	App();
	int Run();
private:
	void Update();
private:
	Window wnd;
	Timer timer;
};