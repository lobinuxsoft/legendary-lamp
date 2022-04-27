#include "raylib.h"
#include "input_system.h"

bool jump() { return IsKeyDown(KEY_SPACE); }

int move()
{
	int result = 0;
	if (IsKeyDown(KEY_A)) 
	{
		result = -1;
	}
	else if(IsKeyPressed(KEY_D))
	{
		result = 1;
	}

	return result;
}