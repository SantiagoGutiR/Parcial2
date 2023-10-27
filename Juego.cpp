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
    cout << "\t0\t1\t2\t3\t4\t5\t6\t7\n";
    for(int i = 0; i < 8 ; i++){
        cout << i << "\t";
        for(int j = 0 ; j < 8 ; j++){
            cout << tablero[i][j] << "\t";
        }
        cout << endl;
    }
}

bool Juego::verificar_arriba(int i, int j){
    if (tablero[i-1][j] == 32 || tablero[i-1][j] == turno){
        return false;
    }
    for (int n = i-2 ; n >= 0 ; n--){
        if ((tablero[n][j] != 32 && tablero[n][j] != turno) && tablero[n+1][j] == turno){
            return false;
        }
        else if (tablero[n][j] == 32){
            // movimiento posible n-j
            cout << n << "-" << j << endl;
            return true;
        }
    }
    return false;
}

bool Juego::verificar_abajo(int i, int j){
    if (tablero[i+1][j] == 32 || tablero[i+1][j] == turno){
        return false;
    }
    for (int n = i+2 ; n < 8 ; n++){
        if ((tablero[n][j] != 32 && tablero[n][j] != turno) && tablero[n-1][j] == turno){
            return false;
        }
        else if (tablero[n][j] == 32){
            // movimiento posible n-j
            cout << n << "-" << j << endl;
            return true;
        }
    }
    return false;
}

bool Juego::verificar_derecha(int i, int j){
    if (tablero[i][j+1] == 32 || tablero[i][j+1] == turno){
        return false;
    }
    for (int n = j+2 ; n < 8 ; n++){
        if ((tablero[i][n] != 32 && tablero[i][n] != turno) && tablero[i][n-1] == turno){
            return false;
        }
        else if (tablero[i][n] == 32){
            // movimiento posible n-j
            cout << i << "-" << n << endl;
            return true;
        }
    }
    return false;
}

bool Juego::verificar_izquierda(int i, int j){
    if (tablero[i][j-1] == 32 || tablero[i][j-1] == turno){
        return false;
    }
    for (int n = j-2 ; n >= 0 ; n--){
        if ((tablero[i][n] != 32 && tablero[i][n] != turno) && tablero[i][n+1] == turno){
            return false;
        }
        else if (tablero[i][n] == 32){
            // movimiento posible n-j
            cout << i << "-" << n << endl;
            return true;
        }
    }
    return false;
}

bool Juego::verificar_digDerAr(int i, int j){
    if (tablero[i-1][j+1] == 32 || tablero[i-1][j+1] == turno){
        return false;
    }
    int x = i-2;
    for (int n = j+2 ; n < 8 ; n++){
        if ((tablero[x][n] != 32 && tablero[x][n] != turno) && tablero[x][n-1] == turno){
            return false;
        }
        else if (tablero[x][n] == 32){
            // movimiento posible n-j
            cout << x << "-" << n << endl;
            return true;
        }
        x--;
    }
    return false;
}

bool Juego::verificar_digDerAb(int i, int j){
    if (tablero[i+1][j+1] == 32 || tablero[i+1][j+1] == turno){
        return false;
    }
    int x = i+2;
    for (int n = j+2 ; n < 8 ; n++){
        if ((tablero[x][n] != 32 && tablero[x][n] != turno) && tablero[x][n-1] == turno){
            return false;
        }
        else if (tablero[x][n] == 32){
            // movimiento posible n-j
            cout << x << "-" << n << endl;
            return true;
        }
        x++;
    }
    return false;
}

bool Juego::verificar_digIzqAr(int i, int j){
    if (tablero[i-1][j-1] == 32 || tablero[i-1][j-1] == turno){
        return false;
    }
    int x = i-2;
    for (int n = j-2 ; n >= 0 ; n--){
        if ((tablero[x][n] != 32 && tablero[x][n] != turno) && tablero[x][n-1] == turno){
            return false;
        }
        else if (tablero[x][n] == 32){
            // movimiento posible n-j
            cout << x << "-" << n << endl;
            return true;
        }
        x--;
    }
    return false;
}

bool Juego::verificar_digIzqAb(int i, int j){
    if (tablero[i+1][j-1] == 32 || tablero[i+1][j-1] == turno){
        return false;
    }
    int x = i+2;
    for (int n = j-2 ; n >= 0 ; n--){
        if ((tablero[x][n] != 32 && tablero[x][n] != turno) && tablero[x][n-1] == turno){
            return false;
        }
        else if (tablero[x][n] == 32){
            // movimiento posible n-j
            cout << x << "-" << n << endl;
            return true;
        }
        x++;
    }
    return false;
}
