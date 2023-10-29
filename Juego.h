#ifndef JUEGO_H
#define JUEGO_H

#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;

class Juego{
private:
    char turno;
    char** tablero;
    int f_negras;
    int f_blancas;
    string jugador_1;
    string jugador_2;
    string fecha;
    string hora;
    string informacion;


public:
    Juego();
    void mostrar_tablero();
    bool verificar_arriba(int i, int j);
    bool verificar_abajo(int i, int j);
    bool verificar_derecha(int i, int j);
    bool verificar_izquierda(int i, int j);
    bool verificar_digDerAr(int i, int j);
    bool verificar_digDerAb(int i, int j);
    bool verificar_digIzqAr(int i, int j);
    bool verificar_digIzqAb(int i, int j);
    void movimiento();
    void jugar();
    void escribir_archivo(string nombre);
    string leer_archivo(string nombre);
    void mostrar_historial();
    ~Juego();
};

#endif // JUEGO_H
