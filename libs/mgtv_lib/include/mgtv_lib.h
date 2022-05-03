#pragma once

#include "raylib.h"

#include <iostream>

using std::string;


// Punto de origen.
enum class ORIGIN_POINT { CORNER_UP_LEFT, CENTER };
// Estado del bot�n.
enum class BUTTON_STATE { NORMAL, SELECTED, PRESSED };
// Texto para establecer en el bot�n.
enum class WRITTEN_OPTION { PLAY, OPTIONS, RETURN, QUIT, RESUME, YES, NO };

namespace mgtv_lib
{
	// Colores del bot�n (fondo, grosor y texto).
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
		/// Un bot�n con contorno negro que responde ante las acciones del mouse. Su punto de origen es el centro.
		/// </summary>
		/// <param name="x: ">La posici�n sobre el eje X.</param>
		/// <param name="y: ">La posici�n sobre el eje Y.</param>
		/// <param name="size: ">El tama�o equivale a la altura del bot�n. El ancho equivale al doble de su alto.</param>
		/// <param name="writtenOption: ">Texto preseleccionado del bot�n.</param>
		/// <param name="buttonColor: ">El color del fondo del bot�n.</param>
		/// <param name="textColor: ">El color del texto del bot�n. Es negro por defecto.</param>
		/// <param name="thicknessColor: ">El color del grosor del bot�n. Es negro por defecto.</param>
		Button(float x, float y, float size, WRITTEN_OPTION writtenOption, Color buttonColor, Color textColor = BLACK, Color thicknessColor = BLACK);
		~Button();

		/// <summary>
		/// Actualiza el estado del bot�n. Permite la interacci�n con el cursor del mouse.
		/// </summary>
		void update();

		/// <summary>
		/// Dibuja el bot�n.
		/// </summary>
		void draw();


		/// <summary>
		/// Habilita el bot�n.
		/// </summary>
		void enable();

		/// <summary>
		/// Deshabilita el bot�n, dej�ndolo inutilizable hasta que se vuelva a habilitar.
		/// </summary>
		void disable();


		/// <summary>
		/// Pregunta si se entr� al bot�n a trav�s de un clic.
		/// Para que este m�todo funcione, se debe llamar antes del update del propio bot�n.
		/// </summary>
		/// <returns>True si el bot�n estaba presionado y se solt�. En el caso contrario, devuelve false.</returns>
		bool wasClicked();

	private:
		Rectangle buttonRectangle; // Rect�ngulo con su posici�n y dimensiones.

		ORIGIN_POINT originPoint; // Campo de enumerador para saber el punto de origen.
		Vector2 origin; // Punto de origen.

		ButtonColors baseColors; // Color original del bot�n.
		ButtonColors buttonColors; // Color actual del bot�n (el que se va a modificar en ejecuci�n).

		ButtonColors lighterColors; // Color del bot�n seleccionado.
		ButtonColors darkerColors; // Color del bot�n presionado.
		ButtonColors disabledColors; // Color del bot�n inhabilitado.

		int thickness; // Grosor del contorno en p�xeles.

		WRITTEN_OPTION writtenOption; // Campo de enumerador para elegir entre textos preestablecidos para el bot�n.
		string text; // Texto que va a ir escrito sobre el bot�n.

		bool enabled; // Campo para verificar si el bot�n est� habilitado o no.

		BUTTON_STATE buttonState; // Enumerador para comprobar el estado del bot�n (presionado, seleccionado, etc).

		// M�todos para inicializar.
		void initEnabled(bool isEnabled);
		void initPositionAndSize(float x, float y, float size);
		void initOrigin(ORIGIN_POINT originPoint);
		void initColors(Color color, Color textColor, Color thicknessColor);
		void initButtonText(WRITTEN_OPTION writtenOption);
		void initThickness(int thickness);
		Color getNewColor(Color originalColor, BUTTON_STATE buttonState);
		Color getColorInGrayScale(Color color);

		// M�todo para el update para verificar las acciones del mouse.
		void checkMouseActions();

		// M�todos para dibujar.
		void drawRectangle();
		void drawRectangleThickness();
		void writeTextInButton();

		// M�todos de verificaci�n.
		bool isTheCursorInside();
		bool isClicking();

		// M�todos para la apariencia del bot�n.
		void lightenButton();
		void darkenButton();
		void normalizeButton();
		void disableButton();
	};
}
