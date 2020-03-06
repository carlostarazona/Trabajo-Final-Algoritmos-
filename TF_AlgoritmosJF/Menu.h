#include <iostream>
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace std;

class CMenu
{
private:
	int Ancho_mapa1;
	int Largo_mapa1;
	int Ancho_mapa2;
	int Largo_mapa2;
	int i;
	int score;
	bool GameStart;
public:
	CMenu()
	{
		Ancho_mapa1 = 1699;
		Largo_mapa1 = 845;

		Ancho_mapa2 = 100;
		Largo_mapa2 = 40;

		i = 0;
		score = false;
		GameStart = false;
	}
	~CMenu();
	void DibujarMenu(Bitmap^ Img_menu1, Bitmap^ Img_menu2, Bitmap^ Img_backScores, Bitmap^ Img_ScoreChart, BufferedGraphics^buffer, int AnchoPantalla, int LargoPantalla)
	{
		if (score == true)
		{
			Rectangle Origen_mapa1 = Rectangle(0, 0, 427, 220);
			Rectangle Pantalla_mapa1 = Rectangle(0, 0, AnchoPantalla, LargoPantalla);

			Rectangle Origen_mapa2 = Rectangle(0, 0, 1200, 900);
			Rectangle Pantalla_mapa2 = Rectangle(20, 20,950,450);

			buffer->Graphics->DrawImage(Img_backScores, Pantalla_mapa1, Origen_mapa1, GraphicsUnit::Pixel);
			buffer->Graphics->DrawImage(Img_ScoreChart, Pantalla_mapa2, Origen_mapa2, GraphicsUnit::Pixel);
		}
		else
		{
			Rectangle Origen_mapa1 = Rectangle(0, 0, Ancho_mapa1, Largo_mapa1);
			Rectangle Pantalla_mapa1 = Rectangle(0, 0, AnchoPantalla, LargoPantalla);

			Rectangle Origen_mapa2 = Rectangle(0, i*Largo_mapa2, Ancho_mapa2, Largo_mapa2);
			Rectangle Pantalla_mapa2 = Rectangle(350, 290, 3 * Ancho_mapa2, 3 * Largo_mapa2);

			buffer->Graphics->DrawImage(Img_menu1, Pantalla_mapa1, Origen_mapa1, GraphicsUnit::Pixel);
			buffer->Graphics->DrawImage(Img_menu2, Pantalla_mapa2, Origen_mapa2, GraphicsUnit::Pixel);
		}

	}
	void Tecla(Keys tecla)
	{
		if (score == false && tecla == Keys::Up)
		{
			i = 0;
		}
		else if (score == false && tecla == Keys::Down)
		{
			i = 1;
		}
		else if (score == false && tecla == Keys::Enter && i == 0)
		{
			GameStart = true;
		}
		else if (score == false && tecla == Keys::Enter && i == 1)
		{
			score = true;
		}
		else if (score == true && tecla == Keys::Back)
		{
			score = false;
		}
	}
	bool Get_GameStart()
	{
		return GameStart;
	}
	void Set_GameStart(bool gs)
	{
		GameStart = gs;;
	}
};


