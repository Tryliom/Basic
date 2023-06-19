#pragma once

class Display;

namespace DisplayManager
{
	void AddDisplayType(int type, Display* display);
	Display* GetDisplay(int type);
}