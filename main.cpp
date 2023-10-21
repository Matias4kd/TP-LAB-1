#include <iostream> 
#include <string>
#include<ctime>
#include <string>
#include<cstdlib>

using namespace std;
using std::time;
using std::rand;
using std::srand;

#define MAX_JUGADORES 2
#define CANT_AUTORES 3
#define CARTAS 20


void cargar_jugadores(string jugadores[MAX_JUGADORES]){
    
    char confirmacion;
    cout << "CLUTCH" << endl;
    cout << "-------------------------------------------------" << endl << endl;
    
    
    do{
        cout << "Para comenzar ingresar los nombres de los jugadores:" << endl;
        cout << "Jugador 1: ";
        cin >> jugadores[0];
        cout << "Jugador 2: ";
        cin >> jugadores[1];

        cout << "Confirmar Nombres (Y/N): ";
        cin >> confirmacion;

        while(confirmacion != 'n' && confirmacion != 'N' && confirmacion != 'Y' && confirmacion != 'y'){
            cout << "Confirmar nombres con un caracter correcto (Y/N): ";
            cin >> confirmacion;
        }

    }while(confirmacion != 'Y' && confirmacion != 'y');
}


void cargar_juego(string jugadores[MAX_JUGADORES], int puntajes[MAX_JUGADORES], bool &primera_partida){
    
    string mazo_completo[CARTAS]= {"10 CORAZON","10 PICA","10 TREBOL","10 DIAMENTE",
                                 "J CORAZON","J PICA","J TREEBOL","J DIAMANTE",
                                 "Q CORAZON","Q PICA","Q TREBOL","Q DIAMENTE",
                                 "K CORAZON","K PICA","K TREBOL","K DIAMANTE",
                                 "A CORAZON","A PICA","A TREBOL","A DIAMANTE",
                                };
    int posiciones_cartas[CARTAS] = {};
    
    
    
    
    
    
    
    
    
    
    if(primera_partida){
        cargar_jugadores(jugadores);
        primera_partida = false;
    }
    


    
}

int mostrar_estadisticas(string jugadores[MAX_JUGADORES], int puntajes[MAX_JUGADORES]){
    for(int i = 0; i < MAX_JUGADORES;i++){
        cout << "Jugador: " << jugadores[i] << endl;
        cout << "Puntos: " << puntajes[i] << endl;
        cout << "--------" << endl;
        cout << endl;
    }
    int regreso;

    cout << "Ingrese 1 para regresar al menú principal: ";
    cin >> regreso;

    while(regreso != 1){
        cout << "Ingrese 1 para regresar al menú principal: ";
        cin >> regreso;
    }
    return regreso;
    
}

//Entrada: vecctor de autores.
//acción: Impreime el contenido del vector de autores para mostrar los creditos.
int imprimir_Creditos(string autores[CANT_AUTORES]){
    
    cout << endl;
    cout << "GRUPO 7" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << endl;

    for(int i = 0; i < CANT_AUTORES; i++){
        cout << autores[i] << endl;
    }

    cout << endl;
    cout << "---------------------------------------------------" << endl;
    cout << endl;

    int regreso;

    cout << "Ingrese 1 para regresar al menú principal: ";
    cin >> regreso;

    while(regreso != 1){
        cout << "Ingrese 1 para regresar al menú principal: ";
        cin >> regreso;
    }
    return regreso;

}

void cargar_autores (string autores[CANT_AUTORES]){
    autores[0] = "Matías Fourcade - LU: 29773";
    autores[1] = "Tomás Garcia Torres - LU: 27578";
    autores[2] = "Ignacio Martin Becerra - LU: 29699";
}




int main(){

    string jugadores[MAX_JUGADORES] = {};
    string autores[CANT_AUTORES] = {};
    int puntajes [MAX_JUGADORES] = {};
    bool primera_partida = true;

    cargar_autores(autores);    

    int input;
    char confirmacion;
    cout << "CLUTCH" << endl;
    cout <<"----------------------------------" << endl;
    cout << "1 - JUGAR" << endl;
    cout << "2 - ESTADÍSTICAS" << endl;
    cout << "3 - CRÉDITOS" << endl;
    cout << "---------------------------------" << endl;
    cout << "0 - SALIR" << endl;

    cout << endl << "Seleccione una opción para continuar: ";
    cin >> input;

    if(input == 0){
        cout << "Seguro que desea salir Y/N: " ;
        cin >> confirmacion;
        if(confirmacion =='N' || confirmacion == 'n'){
            cout << endl << "Seleccione una opción para continuar: ";
            cin >> input;
        }else if(confirmacion =='Y' || confirmacion == 'y'){
            input = 0;
        }
    }

    while(input != 0){
        switch (input)
        {
            case 1:
                cargar_juego(jugadores, puntajes, primera_partida);
                break;
            case 2:
                mostrar_estadisticas(jugadores, puntajes);
                break;
            case 3:
                imprimir_Creditos(autores);         
            default:
                break;
        }
        cout << "CLUTCH" << endl;
        cout <<"----------------------------------" << endl;
        cout << "1 - JUGAR" << endl;
        cout << "2 - ESTADÍSTICAS" << endl;
        cout << "3 - CRÉDITOS" << endl;
        cout << "---------------------------------" << endl;
        cout << "0 - SALIR" << endl;
        
        cout << endl << "Seleccione una opción para continuar: ";
        cin >> input;

        if(input == 0){
            cout << "Seguro que desea salir Y/N: " ;
            cin >> confirmacion;
            if(confirmacion =='N' || confirmacion == 'n'){
                cout << endl << "Seleccione una opción para continuar: ";
                cin >> input;
            }else if(confirmacion =='Y' || confirmacion == 'y'){
                input = 0;
            }
        }
    }

    return 0;
}