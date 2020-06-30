#include "App.h"
#include <sstream>
#include <iomanip>

App::App() : wnd(800, 600, "Window")
{
}

int App::Run()
{
	while (true)
	{
		// process all messages pending, but to not block for new messages
		if (const auto ecode = Window::ProcessMessages())
		{
			// if return optional has value, means we're quitting so return exit code
			return *ecode;
		}
		Update();
	}
}

void App::Update()
{
	const float c = sin(timer.Peek()) / 2.0f + 0.5f;
	wnd.Gfx().ClearBuffer(c, c, 1.0f);
	wnd.Gfx().EndFrame();
}
