#include "DisplayManager.h"

#include "Display.h"
#include <map>

std::map<int, Display*> displays;

namespace DisplayManager
{
    void AddDisplayType(int type, Display* display)
	{
		displays[type] = display;
	}

    Display* GetDisplay(int type)
    {
		return displays[type];
	}
}