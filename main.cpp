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

bool se_repite_nro(int numero_random,int posiciones_cartas[CARTAS_TOTALES]){
    for(int i = 0; i <= CARTAS_TOTALES; i++){
        if(numero_random == posiciones_cartas[i]){
            return true;
        }
    }
    return false;
}

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

void jugada(int cartas_J1[CARTAS_JUGADOR],int cartas_J2[CARTAS_JUGADOR],string mazo_completo[CARTAS_TOTALES],int cartas_restantes[CARTAS_RESTANTES], string jugadores[MAX_JUGADORES], int turno,int &carta_bloqueada_J1 ,int &carta_bloqueada_J2){
    srand(time(NULL));
    int dado = 0;
    int tirar_dado;
    int auxiliar_jugada;
    int carta_seleccionada;
    int auxiliar_seleccion;

    cout << endl <<  "Es el turno de " << jugadores[turno] << ". Ingrese 1 para tirar el dado: ";
    cin >> tirar_dado;
    
    while(tirar_dado != 1){
        cout << endl <<  "Es el turno de " << jugadores[turno] << ". Ingrese 1 para tirar el dado: ";
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
                cout << jugadores[0] <<" Selecciona una carta para que no pueda ser intercambiada/robada por " <<jugadores[1] << endl;
                cin >> carta_bloqueada_J1;            
            
            
            }else if(turno == 1){
                cout << jugadores[1] <<" Selecciona una carta para que no pueda ser intercambiada/robada por " <<jugadores[0] << endl;
                cin >> carta_bloqueada_J2;  
            }
            break;

        }
    }
}

bool se_repite_mezcla(int numero_random,int posiciones_nuevas[CARTAS_RESTANTES]){
    for(int i = 0; i < CARTAS_RESTANTES; i++){
        if(numero_random == posiciones_nuevas[i]){
            return true;
        }
    }
    return false;
}

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
void imprimir_mazo(int cartas_restantes[CARTAS_RESTANTES],string mazo_completo[CARTAS_TOTALES]){

    cout << endl << "MAZO RESTANTE: " << endl;
    for(int i = 0; i < CARTAS_RESTANTES; i++){

        cout << mazo_completo[cartas_restantes[i]-1] << endl;
    }
}
*/

void jugar_ronda(string jugadores[MAX_JUGADORES],string mazo_completo[CARTAS_TOTALES],int cartas_J1[CARTAS_JUGADOR],int cartas_J2[CARTAS_JUGADOR],int cartas_restantes[CARTAS_RESTANTES],bool &mano_ordenada,int inicio,int &ronda, int &carta_bloqueada_J1 ,int &carta_bloqueada_J2){
    int turno = inicio;
    
    if(inicio == 0){
        cout << endl <<  "Ronda #: " << ronda << endl;
        imprimir_cartas(mazo_completo,cartas_J1, cartas_J2, jugadores);
        //imprimir_mazo(cartas_restantes,mazo_completo);
        jugada(cartas_J1,cartas_J2,mazo_completo,cartas_restantes,jugadores, turno,carta_bloqueada_J1 , carta_bloqueada_J2);
        mano_ordenada = mano_en_orden(cartas_J1,cartas_J2, mazo_completo);
        mezclar_restantes(cartas_restantes);    
        turno = 1;

        if(!mano_ordenada && turno == 1){
            cout << endl <<  "Ronda #: " << ronda << endl;
            imprimir_cartas(mazo_completo,cartas_J1, cartas_J2, jugadores);
            //imprimir_mazo(cartas_restantes,mazo_completo);
            jugada(cartas_J1,cartas_J2,mazo_completo,cartas_restantes,jugadores,turno,carta_bloqueada_J1 , carta_bloqueada_J2);
            mano_ordenada = mano_en_orden(cartas_J1,cartas_J2, mazo_completo);
            mezclar_restantes(cartas_restantes);
            turno = 0;
        }
        

    }else if(inicio == 1){
        cout << endl <<  "Ronda #: " << ronda << endl;
        imprimir_cartas(mazo_completo,cartas_J1, cartas_J2, jugadores);
        //imprimir_mazo(cartas_restantes,mazo_completo);
        jugada(cartas_J1,cartas_J2,mazo_completo,cartas_restantes,jugadores,turno,carta_bloqueada_J1 , carta_bloqueada_J2);
        mano_ordenada = mano_en_orden(cartas_J1,cartas_J2, mazo_completo);
        mezclar_restantes(cartas_restantes);
        turno = 0;

        if(!mano_ordenada && turno == 0){
            cout << endl <<  "Ronda #: " << ronda << endl;
            imprimir_cartas(mazo_completo,cartas_J1, cartas_J2, jugadores);
            //imprimir_mazo(cartas_restantes,mazo_completo);
            jugada(cartas_J1,cartas_J2,mazo_completo,cartas_restantes,jugadores,turno,carta_bloqueada_J1 , carta_bloqueada_J2);
            mano_ordenada = mano_en_orden(cartas_J1,cartas_J2, mazo_completo);
            mezclar_restantes(cartas_restantes);
            turno = 1;
        }
    }
    ronda++;
}



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

        jugar_ronda(jugadores,mazo_completo,cartas_J1,cartas_J2,cartas_restantes,mano_ordenada,inicio,ronda,carta_bloqueada_J1 , carta_bloqueada_J2);

    }

    cout << "Ingrese 1 para regresar al menú principal: ";
    cin >> regreso;

    while(regreso != 1){
        cout << "Ingrese 1 para regresar al menú principal: ";
        cin >> regreso;
    }
    return regreso;
    
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
//acción: Imprime el contenido del vector de autores para mostrar los creditos.
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