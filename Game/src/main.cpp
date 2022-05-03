#include "input_system.h"
#include "CaveLib.h"
#include "RamiLib.h"
#include "FranLib.h"
#include "pichlib.h"
#include "mgtv_lib.h"
#include "PierpaLib.h"

using namespace mgtv_lib;


void verifyClickOnButtons(Button* b1, Button* b2, Button* b3);
void updateButtons(Button* b1, Button* b2, Button* b3);
void drawButtons(Button* b1, Button* b2, Button* b3);

void Run()
{
	// Initialization (Note windowTitle is unused on Android)
	//---------------------------------------------------------
	InitWindow(600, 450, "Legendary Lamp");

	//gameIcon = LoadImage(gameIconUrl);
	//SetWindowIcon(gameIcon);

	//InitGame();

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------
	Texture2D texture = loadTexture("bojji.png");

	Button* button1 = new Button(300.0f, 125.0f, 75.0f, WRITTEN_OPTION::QUIT, RED);
	Button* button2 = new Button(125.0f, 325.0f, 75.0f, WRITTEN_OPTION::YES, LIME);
	Button* button3 = new Button(475.0f, 325.0f, 75.0f, WRITTEN_OPTION::NO, DARKGREEN);
	button2->disable();
	button3->disable();

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		verifyClickOnButtons(button1, button2, button3); // Verifica acciones con el mouse.
		updateButtons(button1, button2, button3); // Actualiza el estado de los botones.

		BeginDrawing();
		ClearBackground(BLACK);

		drawButtons(button1, button2, button3); // Dibuja los botones.
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

void verifyClickOnButtons(Button* b1, Button* b2, Button* b3)
{
	if (b1->wasClicked())
	{
		b1->disable();
		b2->enable();
		b3->enable();
	}
	if (b2->wasClicked())
	{
		CloseWindow();
		exit(0);
	}
	if (b3->wasClicked())
	{
		b1->enable();
		b2->disable();
		b3->disable();
	}
}
void updateButtons(Button* b1, Button* b2, Button* b3)
{
	b1->update();
	b2->update();
	b3->update();
}
void drawButtons(Button* b1, Button* b2, Button* b3)
{
	b1->draw();
	b2->draw();
	b3->draw();
}