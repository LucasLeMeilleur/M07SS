#include <iostream>
#include <tchar.h>
#include "IRClientUDP.h"
#include <string>
#include <stdlib.h>
#include "TelloClientUDP.h"

int _tmain(int argc, _TCHAR* argv[])
{

    TelloClientUDP tello;
    std::string cmd;

    do{

        std::cout << "        C       ciel                                      \n";
        std::cout << "        S       sol                                       \n";
        std::cout << "        H       haut                 [H=25cm  HH=50cm ...]\n";
        std::cout << "        B       bas                  [B=25cm  BB=50cm ...]\n";
        std::cout << "        G       gauche               [G=25cm  GG=50cm ...]\n";
        std::cout << "        D       droite               [D=25cm  DD=50cm ...]\n";
        std::cout << "        A       avance               [A=25cm  AA=50cm ...]\n";
        std::cout << "        R       recul                [R=25cm  RR=50cm ...]\n";
        std::cout << "        P       pivoter sens horaire [P=25cm  PP=50cm ...]\n";
        std::cout << "        T       pivoter sens trigo   [T=25cm  TT=50cm ...]\n";
        std::cout << "        M       mode commande        						\n";
        std::cout << "        Q       quitter              						\n\n";
        std::cout << "Votre commande : ";
        std::getline(std::cin,cmd);



        if (cmd == "C") {
            tello.Decoller();
        }
        else if(cmd == "S") {
            tello.Aterrir();
        }
        else if(cmd == "H") {
            tello.Monter(25);
        }
        else if(cmd == "HH") {
            tello.Monter(50);
        }
        else if(cmd == "B") {
            tello.Descendre(25);
        }
        else if(cmd == "BB") {
            tello.Descendre(50);
        }
        else if(cmd == "G") {
            tello.Gauche(25);
        }
        else if(cmd == "GG") {
            tello.Gauche(50);
        }
        else if(cmd == "D") {
            tello.Droite(25);
        }
        else if(cmd == "DD") {
            tello.Droite(50);
        }
        else if(cmd == "A") {
            tello.Avant(50);
        }
        else if(cmd == "AA") {
            tello.Avant(50);
        }
        else if(cmd == "R") {
            tello.Arriere(25);
        }
        else if(cmd == "RR") {
            tello.Arriere(50);
        }
        else if(cmd == "P") {
            tello.TournerHoraire(30);
        }
        else if(cmd == "PP") {
            tello.TournerHoraire(60);
        }
        else if(cmd == "T") {
        	tello.TournerTrigo(30);
        }
        else if(cmd == "TT") {
        	tello.TournerTrigo(60);
        }
        else if(cmd == "M") {
            tello.ModeCommande();
        }
        else if(cmd == "Q") {
        	break;
        }
        else{
            std::cout << "Erreur";
        }

        system("cls");

    }while(true);

    return 0;


}
