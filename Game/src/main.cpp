#include "input_system.h"
#include "CaveLib.h"
#include "RamiLib.h"
#include "FranLib.h"
#include"pichlib.h"

void Run()
{
	// Initialization (Note windowTitle is unused on Android)
	//---------------------------------------------------------
	InitWindow(300, 300, "Legendary Lamp");

	//gameIcon = LoadImage(gameIconUrl);
	//SetWindowIcon(gameIcon);

	//InitGame();

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------
	Texture2D texture = loadTexture("bojji.png");
	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		BeginDrawing();
		ClearBackground(BLACK);
		// Update and Draw
		//----------------------------------------------------------------------------------
		//UpdateDrawGameFrame();
		//----------------------------------------------------------------------------------
		EndDrawing();
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------
	//UnloadGame();         // Unload loaded data (textures, sounds, models...)

	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------
}

void main()
{
	Run();
}