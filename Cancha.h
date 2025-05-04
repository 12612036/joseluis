#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <memory>
#include "Items.h"
 //Modificar  el tamaño de la cancha 7x9, 9x7
#define FILAS 7 //9
#define COLUMNAS 9 //7
#define ANCHOIMAGEN 64
#define ALTOIMAGEN 64

using namespace System::Drawing;

class CCancha {
private:
  //int cancha[FILAS][COLUMNAS];
  //CBloque* cancha[FILAS][COLUMNAS];
  std::unique_ptr<CBloque> cancha[FILAS][COLUMNAS];

public:
  void DefinirCancha();
  void Inicializar();
  void MostrarCancha();
  void PintarCancha(Graphics^ g, Bitmap^ bmpPiso);
  void PintarMatriz(Graphics^ g, Bitmap^ bmpIrrompible, Bitmap^ bmpRrompible);
};
