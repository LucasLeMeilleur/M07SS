#include <iostream>
#include <tchar.h>
#include "IRServeurUDP.h"
#include <string>
#include <fstream>


int main(){

    IRServeurUDP Server;
    std::string Data;


    Server.OuvrirLaSocketDEcoute(8890, "0.0.0.0");

    std::ofstream Log("serveur.log", std::ios_base::app);

    int nb = 0;
    do{
        nb = Server.RecevoirUnMessage(Data, 1000000);

        Log << Data ;
        std::cout << Data;

    }while(nb >0);


    Log.close();


}