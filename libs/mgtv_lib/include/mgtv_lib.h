#pragma once

#include "raylib.h"

#include <iostream>

using std::string;


// Punto de origen.
enum class ORIGIN_POINT { CORNER_UP_LEFT, CENTER };
// Estado del botón.
enum class BUTTON_STATE { NORMAL, SELECTED, PRESSED };
// Texto para establecer en el botón.
enum class WRITTEN_OPTION { PLAY, OPTIONS, RETURN, QUIT, RESUME, YES, NO };

namespace mgtv_lib
{
	// Colores del botón (fondo, grosor y texto).
	struct ButtonColors
	{
		Color color;
		Color thicknessColor;
		Color textColor;
	};

	class Button
	{
	public:
		/// <summary>
		/// Un botón con contorno negro que responde ante las acciones del mouse. Su punto de origen es el centro.
		/// </summary>
		/// <param name="x: ">La posición sobre el eje X.</param>
		/// <param name="y: ">La posición sobre el eje Y.</param>
		/// <param name="size: ">El tamaño equivale a la altura del botón. El ancho equivale al doble de su alto.</param>
		/// <param name="writtenOption: ">Texto preseleccionado del botón.</param>
		/// <param name="buttonColor: ">El color del fondo del botón.</param>
		/// <param name="textColor: ">El color del texto del botón. Es negro por defecto.</param>
		/// <param name="thicknessColor: ">El color del grosor del botón. Es negro por defecto.</param>
		Button(float x, float y, float size, WRITTEN_OPTION writtenOption, Color buttonColor, Color textColor = BLACK, Color thicknessColor = BLACK);
		~Button();

		/// <summary>
		/// Actualiza el estado del botón. Permite la interacción con el cursor del mouse.
		/// </summary>
		void update();

		/// <summary>
		/// Dibuja el botón.
		/// </summary>
		void draw();


		/// <summary>
		/// Habilita el botón.
		/// </summary>
		void enable();

		/// <summary>
		/// Deshabilita el botón, dejándolo inutilizable hasta que se vuelva a habilitar.
		/// </summary>
		void disable();


		/// <summary>
		/// Pregunta si se entró al botón a través de un clic.
		/// Para que este método funcione, se debe llamar antes del update del propio botón.
		/// </summary>
		/// <returns>True si el botón estaba presionado y se soltó. En el caso contrario, devuelve false.</returns>
		bool wasClicked();

	private:
		Rectangle buttonRectangle; // Rectángulo con su posición y dimensiones.

		ORIGIN_POINT originPoint; // Campo de enumerador para saber el punto de origen.
		Vector2 origin; // Punto de origen.

		ButtonColors baseColors; // Color original del botón.
		ButtonColors buttonColors; // Color actual del botón (el que se va a modificar en ejecución).

		ButtonColors lighterColors; // Color del botón seleccionado.
		ButtonColors darkerColors; // Color del botón presionado.
		ButtonColors disabledColors; // Color del botón inhabilitado.

		int thickness; // Grosor del contorno en píxeles.

		WRITTEN_OPTION writtenOption; // Campo de enumerador para elegir entre textos preestablecidos para el botón.
		string text; // Texto que va a ir escrito sobre el botón.

		bool enabled; // Campo para verificar si el botón está habilitado o no.

		BUTTON_STATE buttonState; // Enumerador para comprobar el estado del botón (presionado, seleccionado, etc).

		// Métodos para inicializar.
		void initEnabled(bool isEnabled);
		void initPositionAndSize(float x, float y, float size);
		void initOrigin(ORIGIN_POINT originPoint);
		void initColors(Color color, Color textColor, Color thicknessColor);
		void initButtonText(WRITTEN_OPTION writtenOption);
		void initThickness(int thickness);
		Color getNewColor(Color originalColor, BUTTON_STATE buttonState);
		Color getColorInGrayScale(Color color);

		// Método para el update para verificar las acciones del mouse.
		void checkMouseActions();

		// Métodos para dibujar.
		void drawRectangle();
		void drawRectangleThickness();
		void writeTextInButton();

		// Métodos de verificación.
		bool isTheCursorInside();
		bool isClicking();

		// Métodos para la apariencia del botón.
		void lightenButton();
		void darkenButton();
		void normalizeButton();
		void disableButton();
	};
}
