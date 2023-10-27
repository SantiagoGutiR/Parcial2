#ifndef JUEGO_H
#define JUEGO_H

#include <iostream>
#include <string>
using namespace std;

class Juego{
private:
    char turno;
    char** tablero;
    int f_negras;
    int f_blancas;

public:
    Juego();
    void mostrar_tablero();
    bool vereficar_arriba(int i, int j);
    bool vereficar_abajo(int i, int j);
    bool vereficar_derecha(int i, int j);
    bool vereficar_izquierda(int i, int j);

};

#endif // JUEGO_H
