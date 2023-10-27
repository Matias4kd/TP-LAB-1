# TP-LAB-1
// Placeholder 



NOTAS A TENER EN CUENTA:


- CONSULTAR POR DADOS PARA DECIDIR TURNO EN CASO DE EMPATE

- CONSULTAR SI EL BLOQUEO DE LA CARTA DURA TODA LA PARTIDA O SOLO EL TURNO SIGUIENTE



PARA PEDIR QUE TIRE EL DADO:

cout << endl <<  "TURNO DE: " << jugadores[turno] << "."<< endl << "Ingrese 1 para tirar el dado: ";
    cin >> tirar_dado;
    
    while(tirar_dado != 1){
        cout << endl <<  "TURNO DE: " << jugadores[turno] << "."<< endl << "Ingrese 1 para tirar el dado: ";
        cin >> tirar_dado;
    }

    if(tirar_dado == 1){
        dado = rand()%6 + 1;
    }