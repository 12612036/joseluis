#include "Jugador.h"

CJugador::CJugador() {};

CJugador::~CJugador() {};

CJugador::CJugador(int x, int y) {
	this->x = x;
	this->y = y;
	dx = 0;
	dy = 0;
	ultimaTecla = EDireccion::Abajo;
	direccion = EDireccion::Ninguna;
	indiceX = 0;
	indiceY = 2;
  for (int i = 0; i < HABILIDADES; i++) {
    habilidades[i] = false;
  }    
}

void CJugador::setDireccion(EDireccion direccion) {
  this->direccion = direccion;
}

void CJugador::Dibujar(Graphics^ g, Bitmap^ bmpJugador) {

    int anchoExacto = ANCHO+1; 
    int altoExacto = ALTO;    

    // Calcular las coordenadas exactas en el sprite sheet
    int origenX = indiceX * anchoExacto;
    int origenY = indiceY * altoExacto;

    // Verificar que no nos salgamos de los límites
    if (origenX + anchoExacto > bmpJugador->Width) {
        origenX = 0;
    }
    if (origenY + altoExacto > bmpJugador->Height) {
        origenY = 0;
    }

    Rectangle porcionOrigen = Rectangle(origenX, origenY, anchoExacto, altoExacto);

    int anchoNuevo = static_cast<int>(ANCHO * FACTORZOOM);
    int altoNuevo = static_cast<int>(ALTO * FACTORZOOM);

    Rectangle areaDestino = Rectangle(x, y, anchoNuevo, altoNuevo);

    //Configuraciones para mejorar la calidad de la imagen
    g->InterpolationMode = System::Drawing::Drawing2D::InterpolationMode::NearestNeighbor;
    g->PixelOffsetMode = System::Drawing::Drawing2D::PixelOffsetMode::Half;
    g->CompositingQuality = System::Drawing::Drawing2D::CompositingQuality::HighQuality;
    g->DrawImage(bmpJugador, areaDestino, porcionOrigen, GraphicsUnit::Pixel);
}

void CJugador::Mover(Graphics^ g, Bitmap^ bmpJugador) {
  switch (direccion) {
    case EDireccion::Arriba:
      indiceY = 0;
      if ((indiceX >= 0) && (indiceX < 3)) {
        indiceX++;
      } else {
        indiceX = 0;
      }
      dx = 0;
      dy = -10;
      ultimaTecla = EDireccion::Arriba;
      break;
    case EDireccion::Abajo:
      indiceY = 2;
      if ((indiceX >= 0) && (indiceX < 3)) {
        indiceX++;
      } else {
        indiceX = 0;
      }
      dx = 0;
      dy = 10;
      ultimaTecla = EDireccion::Abajo;
      break;
    case EDireccion::Izquierda:
      indiceY = 3;
      if ((indiceX >= 0) && (indiceX < 3)) {
        indiceX++;
      } else {
        indiceX = 0;
      }
      dx = -10;
      dy = 0;
      ultimaTecla = EDireccion::Izquierda;
      break;
    case EDireccion::Derecha:
      indiceY = 1;
      if ((indiceX >= 0) && (indiceX < 3)) {
        indiceX++;
      } else {
        indiceX = 0;
      }
      dx = 10;
      dy = 0;
      ultimaTecla = EDireccion::Derecha;
      break;
    case EDireccion::Ninguna:
      dx = 0;
      dy = 0;
      switch (ultimaTecla) {
        case EDireccion::Abajo:
          indiceX = 0;
          indiceY = 2;
          break;
        case EDireccion::Arriba:
          indiceX = 0;
          indiceY = 0;
          break;
        case EDireccion::Izquierda:
          indiceX = 3; //Cambiamos para que encaje con la imagen de la izquierda
          indiceY = 3;
          break;        
        case EDireccion::Derecha:
          indiceX = 0; //Cambiamos de 1 a 0 para la primera imagene del tick
          indiceY = 1; //Cambiamos de 3 a 1 para usar la fila correcta
          break;
      }
      break;      
  }

  //Actualizamos la posicion del jugador aplicando dx y dy
  x += dx;
  y += dy;

  Dibujar(g, bmpJugador);
}
