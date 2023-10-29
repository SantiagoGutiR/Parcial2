#include "Juego.h"

int main()
{
    int controlador = 0;
    Juego partida;
    cout << "1. Si desea jugar una partida\n"
            "2. Si desea ver el historial de partidas\n"
            "Ingrese lo que desea hacer:";
    cin >> controlador;
    if(controlador == 1) partida.jugar();
    else if (controlador == 2)partida.mostrar_historial();
    return 0;
}
