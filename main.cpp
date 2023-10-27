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
#define CARTAS_TOTALES 20
#define CARTAS_RESTANTES 10
#define CARTAS_JUGADOR 5

//Entrada: Recibe el vector de jugadores y solicita los nombres.
//Salida: Devuelve el vector de jugadores con los nombres correspondientes.
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

//Entrada: Recibe el numero random y el vector de posiciones para el mazo completo.
//Salida: Devuelve si el numero generado ya fue asignado dentro del vector de posiciones.
bool se_repite_nro(int numero_random,int posiciones_cartas[CARTAS_TOTALES]){
    for(int i = 0; i <= CARTAS_TOTALES; i++){
        if(numero_random == posiciones_cartas[i]){
            return true;
        }
    }
    return false;
}

//Entrada: Recibe el mazo comleto junto al vector que tendra las posiciones de las cartas.
//Salida: Devuelve el mazo con las posiciones mezcladas en el vector de posiciones.
void mezclar_mazo_completo(string mazo_completo[CARTAS_TOTALES],int posiciones_cartas[CARTAS_TOTALES]){
    
    int numero_random;
    string auxiliar_mezcla;
    
    for(int i = 0; i < CARTAS_TOTALES;i++){
        numero_random = rand()%21;

        while(se_repite_nro(numero_random, posiciones_cartas)|| numero_random == 0){
            numero_random = rand()%21;
        }

        posiciones_cartas[i] = numero_random;
    }   
    
}

//Entrada: Recibe el vector de posiciones del mazo.
//Salida: Carga los vectores de los jugadores y cartas restantes para repartir las cartas.
void repartir_cartas(int posiciones_cartas[CARTAS_TOTALES], int cartas_restantes[CARTAS_RESTANTES], int cartas_J1[CARTAS_JUGADOR], int cartas_J2[CARTAS_JUGADOR]){
    bool cartas_servidas = false;
    
    for(int i = 0; i < CARTAS_JUGADOR;i++){
        cartas_J1[i] =  posiciones_cartas[i];
        cartas_J2[i] = posiciones_cartas[i+5];
        
    }
    for(int i = 0; i < CARTAS_RESTANTES;i++){
        cartas_restantes[i] = posiciones_cartas[i+10];
    }

}

//Entrada: Recibe las manos de cada jugador y el vector del mazo.
//Salida: Devuelve si el mazo esta ordenado o no.
bool mano_en_orden(int cartas_J1[CARTAS_JUGADOR],int cartas_J2[CARTAS_JUGADOR],string mazo_completo[CARTAS_TOTALES]){

    if(mazo_completo[cartas_J1[0]-1]=="10 CORAZON" || mazo_completo[cartas_J1[0]-1]=="10 PICA" || mazo_completo[cartas_J1[0]-1]=="10 TREBOL"|| mazo_completo[cartas_J1[0]-1]=="10 DIAMANTE"){
        if(mazo_completo[cartas_J1[1]-1]=="J CORAZON" || mazo_completo[cartas_J1[1]-1]=="J PICA" || mazo_completo[cartas_J1[1]-1]=="J TREBOL"|| mazo_completo[cartas_J1[1]-1]=="J DIAMANTE"){
            if(mazo_completo[cartas_J1[2]-1]=="Q CORAZON" || mazo_completo[cartas_J1[2]-1]=="Q PICA" || mazo_completo[cartas_J1[2]-1]=="Q TREBOL"|| mazo_completo[cartas_J1[2]-1]=="Q DIAMANTE"){
                if(mazo_completo[cartas_J1[3]-1]=="K CORAZON" || mazo_completo[cartas_J1[3]-1]=="K PICA" || mazo_completo[cartas_J1[3]-1]=="K TREBOL"|| mazo_completo[cartas_J1[3]-1]=="K DIAMANTE"){
                    if(mazo_completo[cartas_J1[4]-1]=="A CORAZON" || mazo_completo[cartas_J1[4]-1]=="A PICA" || mazo_completo[cartas_J1[4]-1]=="A TREBOL"|| mazo_completo[cartas_J1[4]-1]=="A DIAMANTE"){
                        return true;
                    }
                }
            }
        }
    }

    if(mazo_completo[cartas_J2[0]-1]=="10 CORAZON" || mazo_completo[cartas_J2[0]-1]=="10 PICA" || mazo_completo[cartas_J2[0]-1]=="10 TREBOL"|| mazo_completo[cartas_J2[0]-1]=="10 DIAMANTE"){
        if(mazo_completo[cartas_J2[1]-1]=="J CORAZON" || mazo_completo[cartas_J2[1]-1]=="J PICA" || mazo_completo[cartas_J2[1]-1]=="J TREBOL"|| mazo_completo[cartas_J2[1]-1]=="J DIAMANTE"){
            if(mazo_completo[cartas_J2[2]-1]=="Q CORAZON" || mazo_completo[cartas_J2[2]-1]=="Q PICA" || mazo_completo[cartas_J2[2]-1]=="Q TREBOL"|| mazo_completo[cartas_J2[2]-1]=="Q DIAMANTE"){
                if(mazo_completo[cartas_J2[3]-1]=="K CORAZON" || mazo_completo[cartas_J2[3]-1]=="K PICA" || mazo_completo[cartas_J2[3]-1]=="K TREBOL"|| mazo_completo[cartas_J2[3]-1]=="K DIAMANTE"){
                    if(mazo_completo[cartas_J2[4]-1]=="A CORAZON" || mazo_completo[cartas_J2[4]-1]=="A PICA" || mazo_completo[cartas_J2[4]-1]=="A TREBOL"|| mazo_completo[cartas_J2[4]-1]=="A DIAMANTE"){
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

//Entrada: Recibe las manos de los jugadores y el mazo de cartas.
//Salida: Devuelve que persona arranca la partida segun los criterios de la consigna.
int quien_arranca(string mazo_completo[CARTAS_TOTALES],int cartas_J1[CARTAS_JUGADOR],int cartas_J2[CARTAS_JUGADOR]){
    int contadores_cartas_j1[CARTAS_JUGADOR] = {}; // indice 0 corresponde a contador de Aces, de ahi de forma descendiente hasta el indice 4(contador de dieces).
    int contadores_cartas_j2[CARTAS_JUGADOR] = {}; // indice 0 corresponde a contador de Aces, de ahi de forma descendiente hasta el indice 4(contador de dieces).

    
    for(int i = 0; i < CARTAS_JUGADOR; i++){

        if(mazo_completo[cartas_J1[i]-1] == "A CORAZON"||mazo_completo[cartas_J1[i]-1] =="A PICA"||mazo_completo[cartas_J1[i]-1] =="A TREBOL"||mazo_completo[cartas_J1[i]-1] =="A DIAMANTE"){
            contadores_cartas_j1[0]++;
        }
        if(mazo_completo[cartas_J2[i]-1] == "A CORAZON"||mazo_completo[cartas_J2[i]-1] =="A PICA"||mazo_completo[cartas_J2[i]-1] =="A TREBOL"||mazo_completo[cartas_J2[i]-1] =="A DIAMANTE"){
            contadores_cartas_j2[0]++;
        }

        if(mazo_completo[cartas_J1[i]-1] == "K CORAZON"||mazo_completo[cartas_J1[i]-1] =="K PICA"||mazo_completo[cartas_J1[i]-1]=="K TREBOL"||mazo_completo[cartas_J1[i]-1]=="K DIAMANTE"){
            contadores_cartas_j1[1]++;
        }
        if(mazo_completo[cartas_J2[i]-1] == "K CORAZON"||mazo_completo[cartas_J2[i]-1] =="K PICA"||mazo_completo[cartas_J2[i]-1]=="K TREBOL"||mazo_completo[cartas_J2[i]-1]=="K DIAMANTE"){
            contadores_cartas_j2[1]++;
        }

        if(mazo_completo[cartas_J1[i]-1] == "Q CORAZON"||mazo_completo[cartas_J1[i]-1] =="Q PICA"||mazo_completo[cartas_J1[i]-1]=="Q TREBOL"||mazo_completo[cartas_J1[i]-1]=="Q DIAMANTE"){
            contadores_cartas_j1[2]++;
        }
        if(mazo_completo[cartas_J2[i]-1] == "Q CORAZON"||mazo_completo[cartas_J2[i]-1] =="Q PICA"||mazo_completo[cartas_J2[i]-1]=="Q TREBOL"||mazo_completo[cartas_J2[i]-1]=="Q DIAMANTE"){
            contadores_cartas_j2[2]++;
        }

        if(mazo_completo[cartas_J1[i]-1] == "J CORAZON"||mazo_completo[cartas_J1[i]-1] =="J PICA"||mazo_completo[cartas_J1[i]-1]=="J TREBOL"||mazo_completo[cartas_J1[i]-1]=="J DIAMANTE"){
            contadores_cartas_j1[3]++;
        }
        if(mazo_completo[cartas_J2[i]-1] == "J CORAZON"||mazo_completo[cartas_J2[i]-1] =="J PICA"||mazo_completo[cartas_J2[i]-1]=="J TREBOL"||mazo_completo[cartas_J2[i]-1]=="J DIAMANTE"){
            contadores_cartas_j2[3]++;
        }

        if(mazo_completo[cartas_J1[i]-1] == "10 CORAZON"||mazo_completo[cartas_J1[i]-1] =="10 PICA"||mazo_completo[cartas_J1[i]-1]=="10 TREBOL"||mazo_completo[cartas_J1[i]-1]=="10 DIAMANTE"){
            contadores_cartas_j1[4]++;
        }
        if(mazo_completo[cartas_J2[i]-1] == "10 CORAZON"||mazo_completo[cartas_J2[i]-1] =="10 PICA"||mazo_completo[cartas_J2[i]-1]=="10 TREBOL"||mazo_completo[cartas_J2[i]-1]=="10 DIAMANTE"){
            contadores_cartas_j2[4]++;
        }
    }

    if(contadores_cartas_j1[0] > contadores_cartas_j2[0]){
        return 0;
    }else if(contadores_cartas_j1[0] < contadores_cartas_j2[0]){
        return 1;
    }

    if(contadores_cartas_j1[1] > contadores_cartas_j2[1]){
        return 0;
    }else if(contadores_cartas_j1[1] < contadores_cartas_j2[1]){
        return 1;
    }

    if(contadores_cartas_j1[2] > contadores_cartas_j2[2]){
        return 0;
    }else if(contadores_cartas_j1[2] < contadores_cartas_j2[2]){
        return 1;
    }

    if(contadores_cartas_j1[3] > contadores_cartas_j2[3]){
        return 0;
    }else if(contadores_cartas_j1[3] < contadores_cartas_j2[3]){
        return 1;
    }

    if(contadores_cartas_j1[4] > contadores_cartas_j2[4]){
        return 0;
    }else if(contadores_cartas_j1[4] < contadores_cartas_j2[4]){
        return 1;
    }

    return 3; // CONSULTAR QUE PASA SI EMPATAN EN TODOS LOS NUMEROS (TIRAR DADO?)
}

//Entrada: Recibe las manos de los jugadores, el vector de jugadores y el mazo de cartas.
//Salida: Imprime por pantalla las manos de los jugadores y a quien corresponden.
void imprimir_cartas(string mazo_completo[CARTAS_TOTALES], int cartas_J1[CARTAS_JUGADOR], int cartas_J2[CARTAS_JUGADOR],string jugadores[MAX_JUGADORES]){
    cout << endl << "----------------------" << endl;
    cout << "Cartas "<< jugadores[0] << ": " << endl << endl;
    for(int i = 0; i < CARTAS_JUGADOR; i++){
        cout << "Carta# " << i+1 <<": " << mazo_completo[cartas_J1[i]-1] << endl;
    }
    cout << endl << "----------------------" << endl;
    cout << "Cartas "<< jugadores[1] << ": " << endl << endl;
    for(int i = 0; i < CARTAS_JUGADOR; i++){
        cout << "Carta# " << i+1 <<": " << mazo_completo[cartas_J2[i]-1]  << endl;
    }
}

//Entrada: Recibe toda la informacion necesaria para realizr la jugada y almacenar procesos.
//Salida: devuelve el resultado de la jugada realizada.
void jugada(int cartas_J1[CARTAS_JUGADOR],int cartas_J2[CARTAS_JUGADOR],string mazo_completo[CARTAS_TOTALES],int cartas_restantes[CARTAS_RESTANTES], string jugadores[MAX_JUGADORES], 
  int turno,int &carta_bloqueada_J1 ,int &carta_bloqueada_J2,int &ultimo_evento, bool &J1_robado, bool &J2_robado, bool &J1_salta_turno, bool &J2_salta_turno){

    srand(time(NULL));
    int dado = 0;
    int tirar_dado;
    int auxiliar_jugada;
    int carta_seleccionada;
    int auxiliar_seleccion;

    cout << endl <<  "TURNO DE: " << jugadores[turno] << "."<< endl << "Ingrese 1 para tirar el dado: ";
    cin >> tirar_dado;
    
    while(tirar_dado != 1){
        cout << endl <<  "TURNO DE: " << jugadores[turno] << "."<< endl << "Ingrese 1 para tirar el dado: ";
        cin >> tirar_dado;
    }

    if(tirar_dado == 1){
        dado = rand()%6 + 1;
    }
    cout << endl << "El número del dado es: " << dado << endl;

    if(dado == 6){
        cout << "Sacaste 6!" << endl << "Podes elegir que accion tomar (1 a 5) o ingresar 0 para pasar tu turno: ";
        cin >> dado;
    }

   if(dado != 0){   
        switch (dado)
        {
        case 1:

            if(turno == 0){
                cout << "Seleccione que carta de su corral desea intercambiar con una del mazo (1 a 5): ";
                cin >> carta_seleccionada;

                auxiliar_jugada = cartas_J1[carta_seleccionada - 1];
                cartas_J1[carta_seleccionada-1] = cartas_restantes[0];
                cartas_restantes[0] = auxiliar_jugada;
            
            }else if(turno == 1){
                cout << "Seleccione que carta de su corral desea intercambiar con una del mazo (1 a 5): ";
                cin >> carta_seleccionada;

                auxiliar_jugada = cartas_J2[carta_seleccionada - 1];
                cartas_J2[carta_seleccionada-1] = cartas_restantes[0];
                cartas_restantes[0] = auxiliar_jugada;
            }

            break;

        case 2:

            if(turno == 0){
                cout << "Seleccione que carta de "<< jugadores[1] << " desea intercambiar con una del mazo (1 a 5): ";
                cin >> carta_seleccionada;

                while(carta_seleccionada == carta_bloqueada_J2){
                    cout << "Esa carta se encuentra bloqueada, elija una diferente: ";
                    cin >> carta_seleccionada;
                }

                auxiliar_jugada = cartas_J2[carta_seleccionada - 1];
                cartas_J2[carta_seleccionada-1] = cartas_restantes[0];
                cartas_restantes[0] = auxiliar_jugada;
            
            
            }else if(turno == 1){
                cout << "Seleccione que carta de "<< jugadores[0] << " desea intercambiar con una del mazo (1 a 5): ";
                cin >> carta_seleccionada;

                while(carta_seleccionada == carta_bloqueada_J1){
                    cout << "Esa carta se encuentra bloqueada, elija una diferente: ";
                    cin >> carta_seleccionada;
                }

                auxiliar_jugada = cartas_J1[carta_seleccionada - 1];
                cartas_J1[carta_seleccionada-1] = cartas_restantes[0];
                cartas_restantes[0] = auxiliar_jugada;
            
            }

            break;
    
        case 3:
            if(turno == 0){
                cout << "Seleccione que carta de tu corral para intercambiar con " << jugadores[1] << " (1 a 5): ";
                cin >> carta_seleccionada;

                auxiliar_jugada = cartas_J1[carta_seleccionada - 1];

                cout << "Seleccione que carta le robas a "<< jugadores[1] << " (1 a 5): ";
                cin >> auxiliar_seleccion;

                while(auxiliar_seleccion == carta_bloqueada_J2){
                    cout << "Esa carta se encuentra bloqueada, elija una diferente: ";
                    cin >> auxiliar_seleccion;
                }

                cartas_J1[carta_seleccionada-1] = cartas_J2[auxiliar_seleccion-1];
                cartas_J2[auxiliar_seleccion-1] = auxiliar_jugada;

                J2_robado = true;
            
            
            }else if(turno == 1){
                cout << "Seleccione que carta de tu corral para intercambiar con " << jugadores[0] << " (1 a 5): ";
                cin >> carta_seleccionada;

                auxiliar_jugada = cartas_J2[carta_seleccionada - 1];

                cout << "Seleccione que carta le robas a "<< jugadores[0] << " (1 a 5): ";
                cin >> auxiliar_seleccion;

                while(auxiliar_seleccion == carta_bloqueada_J1){
                    cout << "Esa carta se encuentra bloqueada, elija una diferente: ";
                    cin >> auxiliar_seleccion;
                }

                cartas_J2[carta_seleccionada-1] = cartas_J1[auxiliar_seleccion-1];
                cartas_J1[auxiliar_seleccion-1] = auxiliar_jugada;

                J1_robado = true;
            
            }

            break;

        case 4:
            if(turno == 0){
                cout << jugadores[0] <<" Selecciona dos cartas para cambiar de lugar dentro de tu corral:" << endl;
                cout << "Carta #1: ";
                cin >> carta_seleccionada;
                cout << "Carta #2: ";
                cin >> auxiliar_seleccion;

                auxiliar_jugada = cartas_J1[carta_seleccionada -1];
                cartas_J1[carta_seleccionada-1] = cartas_J1[auxiliar_seleccion -1];
                cartas_J1[auxiliar_seleccion -1] = auxiliar_jugada;
            
            
            }else if(turno == 1){
                cout << jugadores[1] <<" Selecciona dos cartas para cambiar de lugar dentro de tu corral:" << endl;
                cout << "Carta #1: ";
                cin >> carta_seleccionada;
                cout << "Carta #2: ";
                cin >> auxiliar_seleccion;

                auxiliar_jugada = cartas_J2[carta_seleccionada -1];
                cartas_J2[carta_seleccionada-1] = cartas_J2[auxiliar_seleccion -1];
                cartas_J2[auxiliar_seleccion -1] = auxiliar_jugada;
            
            }
            break;
    
        case 5: //consultar si la carta permanece bloqueada despues de que uno mismo la mueva o por el resto del juego.
            if(turno == 0){
                cout << jugadores[0] <<" Selecciona una carta para que no pueda ser intercambiada/robada por " <<jugadores[1] << " (1 a 5): ";
                cin >> carta_bloqueada_J1;            
            
            
            }else if(turno == 1){
                cout << jugadores[1] <<" Selecciona una carta para que no pueda ser intercambiada/robada por " <<jugadores[0] << " (1 a 5): ";
                cin >> carta_bloqueada_J2;  
            }
            break;

        }
    }else{
        if(turno == 0){           
            J1_salta_turno = true;            
        }else if(turno == 1){
            J2_salta_turno = true;
        }
            
    }
    ultimo_evento = dado;
}

//Entrada: Recibe el numero random y el vector de posiciones para el mazo restante.
//Salida: Devuelve si el numero generado ya fue asignado dentro del vector de posiciones para el mazo restante.
bool se_repite_mezcla(int numero_random,int posiciones_nuevas[CARTAS_RESTANTES]){
    for(int i = 0; i < CARTAS_RESTANTES; i++){
        if(numero_random == posiciones_nuevas[i]){
            return true;
        }
    }
    return false;
}

//Entrada: Recibe el mazo restante.
//Salida: Devuelve el mazo restante con las posiciones mezcladas.
void mezclar_restantes(int cartas_restantes[CARTAS_RESTANTES]){
    int auxiliar_cartas_restantes[CARTAS_RESTANTES];
    int numero_random;
    int posiciones_nuevas[CARTAS_RESTANTES] = {};

    for(int i = 0; i < CARTAS_RESTANTES; i++){
        auxiliar_cartas_restantes[i] = cartas_restantes[i];
    }

    for(int i = 0; i < CARTAS_RESTANTES; i++){

        numero_random = rand()%11;

        while(se_repite_mezcla(numero_random,posiciones_nuevas) || numero_random == 0){
            numero_random = rand()%11;
        }
        posiciones_nuevas[i] = numero_random;
    }

    for(int i = 0; i < CARTAS_RESTANTES; i++){
        cartas_restantes[posiciones_nuevas[i]-1] = auxiliar_cartas_restantes[i];
    }

}

/*
//Entrada: Recibe el mazo restante.
//Salida: imprime el mazo restante (para pruebas)
void imprimir_mazo(int cartas_restantes[CARTAS_RESTANTES],string mazo_completo[CARTAS_TOTALES]){

    cout << endl << "MAZO RESTANTE: " << endl;
    for(int i = 0; i < CARTAS_RESTANTES; i++){

        cout << mazo_completo[cartas_restantes[i]-1] << endl;
    }
}
*/

//Entrada:Recibe todos los parametros para jugar la ronda.
//Salida: Mezcla el maso para el siguiente turno y define el ganador
void jugar_ronda(string jugadores[MAX_JUGADORES],string mazo_completo[CARTAS_TOTALES],int cartas_J1[CARTAS_JUGADOR],int cartas_J2[CARTAS_JUGADOR],int cartas_restantes[CARTAS_RESTANTES],
  bool &mano_ordenada,int inicio,int &ronda, int &carta_bloqueada_J1 ,int &carta_bloqueada_J2,int &ultimo_evento, bool &J1_robado, bool &J2_robado, bool &J1_salta_turno, bool &J2_salta_turno,int &ganador){

    int turno = inicio;
    
    if(inicio == 0){
        cout << endl << "CLUTCH" << endl;
        cout << "-------------------------------------" << endl;
        cout << endl <<  "Ronda #: " << ronda << endl;
        imprimir_cartas(mazo_completo,cartas_J1, cartas_J2, jugadores);
        //imprimir_mazo(cartas_restantes,mazo_completo);
        jugada(cartas_J1,cartas_J2,mazo_completo,cartas_restantes,jugadores, turno,carta_bloqueada_J1 , carta_bloqueada_J2, ultimo_evento, J1_robado, J2_robado, J1_salta_turno, J2_salta_turno);
        mano_ordenada = mano_en_orden(cartas_J1,cartas_J2, mazo_completo);
        if(mano_ordenada){
            ganador = 0;
            imprimir_cartas(mazo_completo,cartas_J1, cartas_J2, jugadores);
        }
        mezclar_restantes(cartas_restantes);    
        turno = 1;

        if(!mano_ordenada && turno == 1){
            cout << endl << "CLUTCH" << endl;
            cout << "-------------------------------------" << endl;
            cout << endl <<  "Ronda #: " << ronda << endl;
            imprimir_cartas(mazo_completo,cartas_J1, cartas_J2, jugadores);
            //imprimir_mazo(cartas_restantes,mazo_completo);
            jugada(cartas_J1,cartas_J2,mazo_completo,cartas_restantes,jugadores,turno,carta_bloqueada_J1 , carta_bloqueada_J2, ultimo_evento, J1_robado, J2_robado, J1_salta_turno, J2_salta_turno);
            mano_ordenada = mano_en_orden(cartas_J1,cartas_J2, mazo_completo);
            mezclar_restantes(cartas_restantes);
            if(mano_ordenada){
                ganador = 1;
                imprimir_cartas(mazo_completo,cartas_J1, cartas_J2, jugadores);
            }
            turno = 0;
        }
        

    }else if(inicio == 1){
        cout << endl << "CLUTCH" << endl;
        cout << "-------------------------------------" << endl;
        cout << endl <<  "Ronda #: " << ronda << endl;
        imprimir_cartas(mazo_completo,cartas_J1, cartas_J2, jugadores);
        //imprimir_mazo(cartas_restantes,mazo_completo);
        jugada(cartas_J1,cartas_J2,mazo_completo,cartas_restantes,jugadores,turno,carta_bloqueada_J1 , carta_bloqueada_J2, ultimo_evento, J1_robado, J2_robado, J1_salta_turno, J2_salta_turno);
        mano_ordenada = mano_en_orden(cartas_J1,cartas_J2, mazo_completo);
        mezclar_restantes(cartas_restantes);
        if(mano_ordenada){
            ganador = 1;
        }
        turno = 0;

        if(!mano_ordenada && turno == 0){
            cout << endl << "CLUTCH" << endl;
            cout << "-------------------------------------" << endl;
            cout << endl <<  "Ronda #: " << ronda << endl;
            imprimir_cartas(mazo_completo,cartas_J1, cartas_J2, jugadores);
            //imprimir_mazo(cartas_restantes,mazo_completo);
            jugada(cartas_J1,cartas_J2,mazo_completo,cartas_restantes,jugadores,turno,carta_bloqueada_J1 , carta_bloqueada_J2, ultimo_evento, J1_robado, J2_robado, J1_salta_turno, J2_salta_turno);
            mano_ordenada = mano_en_orden(cartas_J1,cartas_J2, mazo_completo);
            if(mano_ordenada){
                ganador = 0;
            }
            mezclar_restantes(cartas_restantes);
            turno = 1;
        }
    }
    ronda++;
}

//Entrada: Recibe la mano del perdedor y el mazo completo.
//Salida: Compara y devuelve cuantas cartas se encuentran mal ubicadas.
int contar_mal_ubicadas(int jugador[CARTAS_JUGADOR], string mazo_completo[CARTAS_TOTALES]){

    int contador_mal_ubicadas = 0;

    if(mazo_completo[jugador[0]-1] !="10 CORAZON" && mazo_completo[jugador[0]-1]!="10 PICA" && mazo_completo[jugador[0]-1]!="10 TREBOL"&& mazo_completo[jugador[0]-1]!="10 DIAMANTE"){
        contador_mal_ubicadas++;
    }

    if(mazo_completo[jugador[1]-1] !="J CORAZON" && mazo_completo[jugador[1]-1]!="J PICA" && mazo_completo[jugador[1]-1]!="J TREBOL"&& mazo_completo[jugador[1]-1]!="J DIAMANTE"){
        contador_mal_ubicadas++;
    }

    if(mazo_completo[jugador[2]-1] !="Q CORAZON" && mazo_completo[jugador[2]-1]!="Q PICA" && mazo_completo[jugador[2]-1]!="Q TREBOL" && mazo_completo[jugador[2]-1]!="Q DIAMANTE"){
        contador_mal_ubicadas++;
    }

    if(mazo_completo[jugador[3]-1] !="K CORAZON" && mazo_completo[jugador[3]-1]!="K PICA" && mazo_completo[jugador[3]-1]!="K TREBOL" && mazo_completo[jugador[3]-1]!="K DIAMANTE"){
        contador_mal_ubicadas++;
    }

    if(mazo_completo[jugador[4]-1] !="A CORAZON" && mazo_completo[jugador[4]-1]!="A PICA" && mazo_completo[jugador[4]-1]!="A TREBOL" && mazo_completo[jugador[4]-1]!="A DIAMANTE"){
        contador_mal_ubicadas++;
    }
       
    return contador_mal_ubicadas;
}

//Entrada:Recibe los datos necesarios para realizar el calculo del puntaje al finalizar la partida.
//Salida: Imprime por pantalla el resultado de la partida.
void sumar_e_imprimir_puntos(int puntajes[MAX_JUGADORES],int ultimo_evento,bool J1_robado,bool J2_robado,bool J1_salta_turno,bool J2_salta_turno, int ganador, 
  string mazo_completo[CARTAS_TOTALES], int cartas_J1[CARTAS_JUGADOR], int cartas_J2[CARTAS_JUGADOR],string jugadores[MAX_JUGADORES]){

    int const PUNTOS_POR_VICTORIA = 15;
    int const PUNTOS_FINAL_ROBO = 10;
    int const PUNTOS_MALA_UBICACION = 5;
    int const PUNTOS_SIN_PASAR = 10;
    int const PUNTOS_SIN_ROBO = 5;

    int puntos_J1 = 0;
    int puntos_J2 = 0;
    int cartas_mal_ubicadas = 0; 
    int total_mala_ubicacion;
    int total_final_robo = 0;
    int total_sin_pasar = 0;
    int total_sin_robo = 0;
    
    if(ganador == 0){
        puntos_J1 += PUNTOS_POR_VICTORIA;

        if(ultimo_evento == 3){
            puntos_J1 += PUNTOS_FINAL_ROBO;
            total_final_robo = PUNTOS_FINAL_ROBO;
        }

        cartas_mal_ubicadas = contar_mal_ubicadas(cartas_J2,mazo_completo);
        total_mala_ubicacion = cartas_mal_ubicadas*PUNTOS_MALA_UBICACION;

        puntos_J1 += total_mala_ubicacion;

        if(!J1_salta_turno){
            puntos_J1 += PUNTOS_SIN_PASAR;
            total_sin_pasar = PUNTOS_SIN_PASAR;
        }

        if(!J1_robado){
            puntos_J1 += PUNTOS_SIN_ROBO;
            total_sin_robo = PUNTOS_SIN_ROBO;
        }

    }else if(ganador == 1){

        puntos_J2 += PUNTOS_POR_VICTORIA;

        if(ultimo_evento == 3){
            puntos_J2 += PUNTOS_FINAL_ROBO;
            total_final_robo = PUNTOS_FINAL_ROBO;
        }

        cartas_mal_ubicadas = contar_mal_ubicadas(cartas_J1,mazo_completo);
        total_mala_ubicacion = cartas_mal_ubicadas*PUNTOS_MALA_UBICACION;

        puntos_J2 += total_mala_ubicacion;

        if(!J2_salta_turno){
            puntos_J2 += PUNTOS_SIN_PASAR;
            total_sin_pasar = PUNTOS_SIN_PASAR;
        }

        if(!J2_robado){
            puntos_J2 += PUNTOS_SIN_ROBO;
            total_sin_robo = PUNTOS_SIN_ROBO;
        }
    }
    cout << "CLUTCH" << endl;
    cout <<"---------------------------------------------------------------" << endl << endl;
    cout <<"HITO    :                                      " << jugadores[ganador] << endl;
    cout <<"---------------------------------------------------------------" << endl;
    cout << "Ganar la partida:                            +" << PUNTOS_POR_VICTORIA << endl;
    cout << "Robo ultima carta al jugador rival           +" << total_final_robo << endl;
    cout << "Cartas mal ubicadas del rival x" << cartas_mal_ubicadas << "             +" <<total_mala_ubicacion << endl;
    cout << "Sin pasar de turno                           +" << total_sin_pasar << endl;
    cout << "Sin haber sufrido un robo del rival          +" << total_sin_robo << endl;
    cout << "--------------------------------------------------------------" << endl;
    
    if(ganador == 0){
        cout << "TOTAL                                         " << puntos_J1 << endl << endl;
        cout << "GANADOR: " << jugadores[0] << " con " << puntos_J1 << " puntos de victoria." << endl << endl;
    }else if(ganador == 1){
        cout << "TOTAL                                         " << puntos_J2 << endl << endl;
        cout << "GANADOR: " << jugadores[1] << " con " << puntos_J2 << " puntos de victoria." << endl << endl;
    }


    if(puntos_J1 > puntajes[0]){
        puntajes[0] = puntos_J1;
    }else if(puntos_J2 > puntajes[1]){
        puntajes[1] = puntos_J2;
    }

    

}

//Entrada: Recibe el vector de jugadores y los puntajes.
//Saida: Ejecuta la partida y guarda los puntos en caso de que corresponda.
int cargar_juego(string jugadores[MAX_JUGADORES], int puntajes[MAX_JUGADORES], bool &primera_partida){
    int regreso;

    srand(time(NULL));
    string mazo_completo[CARTAS_TOTALES]= {"10 CORAZON","10 PICA","10 TREBOL","10 DIAMANTE",
                                 "J CORAZON","J PICA","J TREBOL","J DIAMANTE",
                                 "Q CORAZON","Q PICA","Q TREBOL","Q DIAMANTE",
                                 "K CORAZON","K PICA","K TREBOL","K DIAMANTE",
                                 "A CORAZON","A PICA","A TREBOL","A DIAMANTE",
                                };
    int posiciones_cartas[CARTAS_TOTALES] = {};
    int cartas_restantes[CARTAS_RESTANTES] = {};
    int cartas_J1[CARTAS_JUGADOR] = {};
    int cartas_J2[CARTAS_JUGADOR] = {};
    bool mano_ordenada = false;
    int inicio = 0;
    int ronda = 1;
    int carta_bloqueada_J1 , carta_bloqueada_J2;
    
    //datos para suma de puntos
    int ganador;

    bool J1_robado = false;
    bool J2_robado = false;
    int ultimo_evento;
    bool J1_salta_turno = false;
    bool J2_salta_turno = false;
   
    mezclar_mazo_completo(mazo_completo, posiciones_cartas); 
    
    if(primera_partida){
        cargar_jugadores(jugadores);
        primera_partida = false;
    }

    repartir_cartas(posiciones_cartas, cartas_restantes, cartas_J1, cartas_J2);

    while(mano_en_orden(cartas_J1,cartas_J2, mazo_completo)){
        mezclar_mazo_completo(mazo_completo, posiciones_cartas);
        repartir_cartas(posiciones_cartas, cartas_restantes, cartas_J1, cartas_J2);
    }
    
    inicio = quien_arranca(mazo_completo,cartas_J1,cartas_J2);
    
    while(inicio == 3){
        inicio = quien_arranca(mazo_completo,cartas_J1,cartas_J2);
    }

    if(inicio == 0){
        cout << endl<< "Arranca: " << jugadores[inicio] << endl;
    }else if(inicio == 1){
        cout << endl<< "Arranca: " << jugadores[inicio] << endl;
    }
    
    while(!mano_ordenada){
        jugar_ronda(jugadores,mazo_completo,cartas_J1,cartas_J2,cartas_restantes,mano_ordenada,inicio,ronda,carta_bloqueada_J1 , 
        carta_bloqueada_J2, ultimo_evento, J1_robado, J2_robado, J1_salta_turno, J2_salta_turno,ganador);
    }

    sumar_e_imprimir_puntos(puntajes,ultimo_evento, J1_robado, J2_robado, J1_salta_turno, J2_salta_turno, ganador, mazo_completo, cartas_J1, cartas_J2,jugadores);

    cout << endl << "Ingrese 1 para regresar al menú principal: ";
    cin >> regreso;

    while(regreso != 1){
        cout << "Ingrese 1 para regresar al menú principal: ";
        cin >> regreso;
    }
    return regreso;
    
}

//Entrada: Recibe los jugadores y los puntajes.
//Salida: Imprime por pantalla el jugador que mas cantidad de puntos haya obtenido.
int mostrar_estadisticas(string jugadores[MAX_JUGADORES], int puntajes[MAX_JUGADORES]){
    
    cout << endl << "ESTADISTICAS: " << endl;
    cout << "-----------------------------------------" << endl << endl;

    if(puntajes[0] > puntajes[1]){
        cout << "El jugador con mayor cantidad de puntos obtenidos en una partida es: " << jugadores[0] << endl;
        cout << "Puntos: " << puntajes[0] << endl << endl; 
    }else if(puntajes[1] > puntajes[0]){
        cout << "El jugador con mayor cantidad de puntos obtenidos en una partida es: " << jugadores[1] << endl;
        cout << "Puntos: " << puntajes[1] << endl << endl;
    }else{
        cout << "Ambos jugadorres consiguieron el mismo puntaje maximo: " << endl;
        cout << "Jugador: " << jugadores[0] << " Puntos: " << puntajes[0] << endl << endl;
        cout << "Jugador: " << jugadores[1] << " Puntos: " << puntajes[1] << endl << endl;
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

//Entrada: Recibe el vector de autores.
//Salida: Imprime el contenido del vector de autores para mostrar los creditos.
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

//Entrada: Recibe el vector de autores.
//Salida: Devuelve el vector cargado con la informacion del grupo.
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

    while(input < 0 || input > 3){
        cout << "CLUTCH" << endl;
        cout <<"----------------------------------" << endl;
        cout << "1 - JUGAR" << endl;
        cout << "2 - ESTADÍSTICAS" << endl;
        cout << "3 - CRÉDITOS" << endl;
        cout << "---------------------------------" << endl;
        cout << "0 - SALIR" << endl;

        cout << endl << "Seleccione una opción valida para continuar: ";
        cin >> input;
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
            }else{
                while(confirmacion != 'Y' && confirmacion != 'y' && confirmacion != 'N' && confirmacion != 'n'){
                    cout << endl << "Seleccione una opción valida para continuar (Y/N): ";
                    cin >> confirmacion;
                }
            }
        }
    }

    return 0;
}