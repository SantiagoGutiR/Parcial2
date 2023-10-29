#include "Juego.h"


Juego::Juego(){
    turno = 45;
    f_negras = 2;
    f_blancas = 2;
    tablero = new char*[8];
    for (int i = 0 ; i < 8 ; i++){
        tablero [i] = new char[8];
        for(int j = 0 ; j < 8 ; j++){
            if((i == 3 || i == 4) && (j == 3 || j == 4)){
                if(i == j){
                    tablero[i][j] = 42;
                }
                else{
                    tablero[i][j] = 45;
                }
            }
            else{
                tablero[i][j] = 32;
            }
        }
        tablero [i][8] = '\0';
    }
}

void Juego::mostrar_tablero(){
    cout << "  0 1 2 3 4 5 6 7\n";
    for(int i = 0; i < 8 ; i++){
        cout << i << " ";
        for(int j = 0 ; j < 8 ; j++){
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }
}

bool Juego::verificar_arriba(int i, int j){
    //Verifica una jugada hacia arriba ingresada si es valida o no
    //Si es valida, voltea las fichas
    if (tablero[i-1][j] == 32 || tablero[i-1][j] == turno){
        return false;
    }
    for (int n = i-2 ; n >= 0 ; n--){
        if (tablero[n][j] == turno){
            if(tablero[i][j] == turno && turno == 45)f_negras--;
            else if(tablero[i][j] == turno && turno == 42)f_blancas--;
            for(; i > n ; i--){
                tablero[i][j] = turno;
                if(turno == 45) {
                    f_negras++;
                    f_blancas--;
                }
                else {
                    f_blancas++;
                    f_negras--;
                }
            }
            if(turno == 45)f_blancas++;
            else f_negras++;
            return true;
        }
        else if(tablero [n][j] == 32) return false;
    }
    return false;
}

bool Juego::verificar_abajo(int i, int j){
    //Verifica una jugada hacia abajo ingresada si es valida o no
    //Si es valida, voltea las fichas
    if (tablero[i+1][j] == 32 || tablero[i+1][j] == turno){
        return false;
    }
    for (int n = i+2 ; n < 8 ; n++){
        if (tablero[n][j] == turno){
            if(tablero[i][j] == turno && turno == 45)f_negras--;
            else if(tablero[i][j] == turno && turno == 42)f_blancas--;
            for (; i < n ; i++){
                tablero[i][j] = turno;
                if(turno == 45) {
                    f_negras++;
                    f_blancas--;
                }
                else {
                    f_blancas++;
                    f_negras--;
                }
            }
            if(turno == 45) f_blancas++;
            else f_negras++;
            return true;
        }
        else if(tablero [n][j] == 32) return false;
    }
    return false;
}

bool Juego::verificar_derecha(int i, int j){
    //Verifica una jugada hacia la derecha ingresada si es valida o no
    //Si es valida, voltea las fichas
    if (tablero[i][j+1] == 32 || tablero[i][j+1] == turno){
        return false;
    }
    for (int n = j+2 ; n < 8 ; n++){
        if (tablero[i][n] == turno){
            if(tablero[i][j] == turno && turno == 45)f_negras--;
            else if(tablero[i][j] == turno && turno == 42)f_blancas--;
            for (; j < n ; j++){
                tablero[i][j] = turno;
                if(turno == 45) {
                    f_negras++;
                    f_blancas--;
                }
                else {
                    f_blancas++;
                    f_negras--;
                }
            }
            if(turno == 45) f_blancas++;
            else f_negras++;
            return true;
        }
        else if(tablero [i][n] == 32) return false;
    }
    return false;
}

bool Juego::verificar_izquierda(int i, int j){
    //Verifica una jugada hacia la izquierda ingresada si es valida o no
    //Si es valida, voltea las fichas
    if (tablero[i][j-1] == 32 || tablero[i][j-1] == turno){
        return false;
    }
    for (int n = j-2 ; n >= 0 ; n--){
        if (tablero[i][n] == turno){
            if(tablero[i][j] == turno && turno == 45)f_negras--;
            else if(tablero[i][j] == turno && turno == 42)f_blancas--;
            for (; j > n ; j--){
                tablero[i][j] = turno;
                if(turno == 45) {
                    f_negras++;
                    f_blancas--;
                }
                else {
                    f_blancas++;
                    f_negras--;
                }
            }
            if(turno == 45) f_blancas++;
            else f_negras++;
            return true;
        }
        else if(tablero [i][n] == 32) return false;
    }
    return false;
}

bool Juego::verificar_digDerAr(int i, int j){
    //Verifica una jugada hacia la diagonal de la derecha hacia arriba ingresada si es valida o no
    //Si es valida, voltea las fichas
    if (tablero[i-1][j+1] == 32 || tablero[i-1][j+1] == turno){
        return false;
    }
    int x = i-2;
    for (int n = j+2 ; n < 8 ; n++){
        if (tablero[x][n] == turno){
            if(tablero[i][j] == turno && turno == 45)f_negras--;
            else if(tablero[i][j] == turno && turno == 42)f_blancas--;
            for (;j < n; j++){
                tablero[i][j] = turno;
                if(turno == 45) {
                    f_negras++;
                    f_blancas--;
                }
                else {
                    f_blancas++;
                    f_negras--;
                }
                i--;
            }
            if(turno == 45) f_blancas++;
            else f_negras++;
            return true;
        }
        else if (tablero[x][n] == 32) return false;
        x--;
    }
    return false;
}

bool Juego::verificar_digDerAb(int i, int j){
    //Verifica una jugada hacia la diagonal de la derecha hacia abajo ingresada si es valida o no
    //Si es valida, voltea las fichas
    if (tablero[i+1][j+1] == 32 || tablero[i+1][j+1] == turno){
        return false;
    }
    int x = i+2;
    for (int n = j+2 ; n < 8 ; n++){
        if (tablero[x][n] == turno){
            if(tablero[i][j] == turno && turno == 45)f_negras--;
            else if(tablero[i][j] == turno && turno == 42)f_blancas--;
            for (;j < n; j++){
                tablero[i][j] = turno;
                if(turno == 45) {
                    f_negras++;
                    f_blancas--;
                }
                else {
                    f_blancas++;
                    f_negras--;
                }
                i++;
            }
            if(turno == 45) f_blancas++;
            else f_negras++;
            return true;
        }
        else if (tablero[x][n] == 32) return false;
        x++;
    }
    return false;
}

bool Juego::verificar_digIzqAr(int i, int j){
    //Verifica una jugada hacia la diagonal de la izquierda hacia arriba ingresada si es valida o no
    //Si es valida, voltea las fichas
    if (tablero[i-1][j-1] == 32 || tablero[i-1][j-1] == turno){
        return false;
    }
    int x = i-2;
    for (int n = j-2 ; n >= 0 ; n--){
        if (tablero[x][n] == turno){
            if(tablero[i][j] == turno && turno == 45)f_negras--;
            else if(tablero[i][j] == turno && turno == 42)f_blancas--;
            for (;j > n; j--){
                tablero[i][j] = turno;
                if(turno == 45) {
                    f_negras++;
                    f_blancas--;
                }
                else {
                    f_blancas++;
                    f_negras--;
                }
                i--;
            }
            if(turno == 45) f_blancas++;
            else f_negras++;
            return true;
        }
        else if (tablero[x][n] == 32) return false;
        x--;
    }
    return false;
}

bool Juego::verificar_digIzqAb(int i, int j){
    //Verifica una jugada hacia la diagonal de la izquierda hacia abajo ingresada si es valida o no
    //Si es valida, voltea las fichas
    if (tablero[i+1][j-1] == 32 || tablero[i+1][j-1] == turno){
        return false;
    }
    int x = i+2;
    for (int n = j-2 ; n >= 0 ; n--){
        if (tablero[x][n] == turno){
            if(tablero[i][j] == turno && turno == 45)f_negras--;
            else if(tablero[i][j] == turno && turno == 42)f_blancas--;
            for (;j > n; j--){
                tablero[i][j] = turno;
                if(turno == 45) {
                    f_negras++;
                    f_blancas--;
                }
                else {
                    f_blancas++;
                    f_negras--;
                }
                i++;
            }
            if(turno == 45) f_blancas++;
            else f_negras++;
            return true;
        }
        else if (tablero[x][n] == 32) return false;
        x++;
    }
    return false;
}

void Juego::movimiento(){
    //Pide una cordanada de un movimiento deseado y lo ejecuta
    //Con sus respectivas restriciones de los limites del tablero
    int i = 10, j = 10;
    cout << "\nIngrese el movimiento que desea realizar...\n"
            "Ingrese la fila: ";
    cin >> i;
    cout << "Ingrese la columna: ";
    cin >> j;
    if (tablero[i][j] == 32){
        //Restriccion fila superior
        if (i == 0){
            if (j == 0){
                if (verificar_derecha(i,j) == false &&
                    verificar_digDerAb(i,j) == false &&
                    verificar_abajo(i,j) == false) cout << "\nMovimiento invalido...\nPasas de turno...\n";
                verificar_derecha(i,j);
                verificar_digDerAb(i,j);
                verificar_abajo(i,j);
            }
            else if(j==7){
                if (verificar_izquierda(i,j) == false &&
                    verificar_digIzqAb(i,j) == false &&
                    verificar_abajo(i,j) == false) cout << "\nMovimiento invalido...\nPasas de turno...\n";
                verificar_izquierda(i,j);
                verificar_digIzqAb(i,j);
                verificar_abajo(i,j);
            }
            else{
                if(verificar_izquierda(i,j) == false &&
                    verificar_digIzqAb(i,j) == false &&
                    verificar_abajo(i,j) == false &&
                    verificar_digDerAb(i,j) == false &&
                    verificar_derecha(i,j) == false)cout << "\nMovimiento invalido...\nPasas de turno...\n";
                verificar_izquierda(i,j);
                verificar_digIzqAb(i,j);
                verificar_abajo(i,j);
                verificar_digDerAb(i,j);
                verificar_derecha(i,j);
            }
        }
        //Restriccion de la fila inferior
        else if (i == 7){
            if (j == 0){
                if (verificar_derecha(i,j) == false &&
                    verificar_digDerAr(i,j) == false &&
                    verificar_arriba(i,j) == false)cout << "\nMovimiento invalido...\nPasas de turno...\n";
                verificar_derecha(i,j);
                verificar_digDerAr(i,j);
                verificar_arriba(i,j);
            }
            else if(j==7){
                if(verificar_izquierda(i,j) == false &&
                    verificar_digIzqAr(i,j) == false &&
                    verificar_arriba(i,j) == false)cout << "\nMovimiento invalido...\nPasas de turno...\n";
                verificar_izquierda(i,j);
                verificar_digIzqAr(i,j);
                verificar_arriba(i,j);
            }
            else{
                if(verificar_izquierda(i,j) == false &&
                    verificar_digIzqAr(i,j) == false &&
                    verificar_arriba(i,j) == false &&
                    verificar_digDerAr(i,j) == false &&
                    verificar_derecha(i,j) == false)cout << "\nMovimiento invalido...\nPasas de turno...\n";
                verificar_izquierda(i,j);
                verificar_digIzqAr(i,j);
                verificar_arriba(i,j);
                verificar_digDerAr(i,j);
                verificar_derecha(i,j);
            }
        }
        //Restriccion de la primera columna
        else if (j == 0){
            if (i == 0){
                if(verificar_derecha(i,j) == false &&
                    verificar_digDerAb(i,j) == false &&
                    verificar_abajo(i,j) == false)cout << "\nMovimiento invalido...\nPasas de turno...\n";
                verificar_derecha(i,j);
                verificar_digDerAb(i,j);
                verificar_abajo(i,j);
            }
            else if(i==7){
                if(verificar_derecha(i,j) == false &&
                    verificar_digDerAr(i,j) == false &&
                    verificar_arriba(i,j) == false)cout << "\nMovimiento invalido...\nPasas de turno...\n";
                verificar_derecha(i,j);
                verificar_digDerAr(i,j);
                verificar_arriba(i,j);
            }
            else{
                if(verificar_arriba(i,j) == false &&
                    verificar_digDerAr(i,j) == false &&
                    verificar_derecha(i,j) == false &&
                    verificar_digDerAb(i,j) == false &&
                    verificar_abajo(i,j) == false)cout << "\nMovimiento invalido...\nPasas de turno...\n";
                verificar_arriba(i,j);
                verificar_digDerAr(i,j);
                verificar_derecha(i,j);
                verificar_digDerAb(i,j);
                verificar_abajo(i,j);
            }
        }
        //Restriccion de la ultima columna
        else if (j == 7){
            if (i == 0){
                if(verificar_izquierda(i,j) == false &&
                    verificar_digIzqAb(i,j) == false &&
                    verificar_abajo(i,j) == false)cout << "\nMovimiento invalido...\nPasas de turno...\n";
                verificar_izquierda(i,j);
                verificar_digIzqAb(i,j);
                verificar_abajo(i,j);
            }
            else if(i==7){
                if(verificar_izquierda(i,j) == false &&
                    verificar_digIzqAr(i,j) == false &&
                    verificar_arriba(i,j) == false)cout << "\nMovimiento invalido...\nPasas de turno...\n";
                verificar_izquierda(i,j);
                verificar_digIzqAr(i,j);
                verificar_arriba(i,j);
            }
            else{
                if(verificar_arriba(i,j) == false &&
                    verificar_digIzqAr(i,j) == false &&
                    verificar_izquierda(i,j) == false &&
                    verificar_digIzqAb(i,j) == false &&
                    verificar_abajo(i,j) == false)cout << "\nMovimiento invalido...\nPasas de turno...\n";
                verificar_arriba(i,j);
                verificar_digIzqAr(i,j);
                verificar_izquierda(i,j);
                verificar_digIzqAb(i,j);
                verificar_abajo(i,j);
            }
        }
        //Interior del cuadro
        else{
            if(verificar_arriba(i,j) == false &&
                verificar_digIzqAr(i,j) == false &&
                verificar_izquierda(i,j) == false &&
                verificar_digIzqAb(i,j) == false &&
                verificar_abajo(i,j) == false &&
                verificar_digDerAb(i,j) == false &&
                verificar_derecha(i,j) == false &&
                verificar_digDerAr(i,j) == false)cout << "\nMovimiento invalido...\nPasas de turno...\n";
            verificar_arriba(i,j);
            verificar_digIzqAr(i,j);
            verificar_izquierda(i,j);
            verificar_digIzqAb(i,j);
            verificar_abajo(i,j);
            verificar_digDerAb(i,j);
            verificar_derecha(i,j);
            verificar_digDerAr(i,j);
        }
    }
    else cout << "Movimiento invalido\nPasas de turno\n";
}

void Juego::jugar(){
    //Aqui tengo parte del menu y que permite interacrtuar con el juego como tal
    int control= 1;
    cout << "\nIngrese el nombre del jugador 1(-): ";
    cin >> jugador_1;
    cout << "Ingrese el nombre del jugador 2(*): ";
    cin >> jugador_2;
    while(control != 0){
        mostrar_tablero();
        cout << "\nFichas del jugardor " << jugador_1 << ": " << f_negras << "\nFichas del jugador " << jugador_2 << ": " << f_blancas << endl;
        if(turno == 45) cout << "Turno del jugador " << jugador_1 << endl;
        else if(turno == 42) cout << "Turno del jugador " << jugador_2 << endl;

        cout << "\n1. Desea realizar un movimiento\n"
                "2. Finalizar el juego\n"
                "Ingrese lo que desea ejecutar: ";
        cin >> control;
        if(control == 1 && f_negras + f_blancas < 64)movimiento();
        else if(control == 2 || f_negras == 0 || f_blancas == 0) control = 0;

        if(turno == 45) turno = 42;
        else if(turno == 42) turno = 45;
    }

    time_t tiempoActual = time(0);
    tm* tiempoLocal = localtime(&tiempoActual);
    fecha = asctime(tiempoLocal);
    hora = fecha.substr(11,5);
    fecha = fecha.substr(4,6);

    //Guardar los datos de la partida en el siguente formato, cada linea es una partida
    //Jugador1,Jugador2,fecha,hora,ganador,fichas
    informacion = leer_archivo("../Registros.txt");
    if(f_negras > f_blancas){
        informacion = informacion + "\n" + jugador_1 + ", " + jugador_2 + ", " + fecha + ", " + hora + ", " + jugador_1 + ", " + to_string(f_negras);
    }
    else if(f_blancas > f_negras){
        informacion = informacion + "\n" + jugador_1 + ", " + jugador_2 + ", " + fecha + ", " + hora + ", " + jugador_2 + ", " + to_string(f_blancas);
    }
    else{
        informacion = informacion + "\n" + jugador_1 + ", " + jugador_2 + ", " + fecha + ", " + hora + ", " + "Empate" + ", " + to_string(f_negras);
    }
    escribir_archivo("../Registros.txt");
}

void Juego::escribir_archivo(string nombre){
    fstream archivo;
    archivo.open(nombre, ios::out | ios::binary);
    archivo << informacion;
    archivo.close();
}



string Juego::leer_archivo(string nombre){
    unsigned long long tamano;
    string informacion1;
    fstream archivo;
    archivo.open(nombre, ios::in | ios::ate | ios::binary);
    if (archivo.is_open()){
        tamano = archivo.tellg();
        archivo.seekg(0);
        for (unsigned long long i = 0 ; i < tamano ; i++){
            informacion1.push_back(archivo.get());
        }

    }
    archivo.close();
    return informacion1;

}

void Juego::mostrar_historial(){
    informacion = leer_archivo("../Registros.txt");
    cout << "\nSe mostrara el historia de las partidas en el fomato...\n"
            "Jugador 1, Jugador 2, fecha, hora, ganador, numero de fichas\n"
            "Partidas:\n";
    cout << informacion;
}

Juego::~Juego(){
    for(int i = 0 ; i < 8 ; i++){
        delete tablero[i];
    }
    delete tablero;
}
