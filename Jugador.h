#pragma once
#include <iostream>
//#include "Items.h"
#define HABILIDADES 7
#define ANCHO 71
#define ALTO 128
#define FACTORZOOM 0.5

using namespace System::Drawing;

enum EDireccion {
	Ninguna = 0,
	Abajo,
	Arriba,
	Izquierda,
	Derecha
};

class CJugador {
	int x;		// posicion en el eje X
	int y;		// posicion en el eje y
	int dx;	// desplazamiento en x
	int dy;	// desplazamiento en y
	int indiceX;
	int indiceY;
	EDireccion ultimaTecla;
	EDireccion direccion;
	bool habilidades[HABILIDADES];
public:
	CJugador();
	~CJugador();
	
	CJugador(int x, int y);
	void Dibujar(Graphics^ g, Bitmap^ bmpJugador);
	void Mover(Graphics^ g, Bitmap^ bmpJugador);
	void setDireccion(EDireccion direccion);
};