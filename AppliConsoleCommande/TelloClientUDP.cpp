//---------------------------------------------------------------------------

#pragma hdrstop

#include "TelloClientUDP.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#include <sstream>
#include <string>



TelloClientUDP::TelloClientUDP(){

    client.OuvrirLaSocketDeCommunication("127.0.0.1",8889);
}

std::string TelloClientUDP::EnvoyerCommande(std::string commande){
    client.EnvoyerUnMessage(commande);


    std::string msg;
    client.RecevoirUnMessage(msg);
    if(std::empty(msg)) return "";
    else return msg;
}


std::string TelloClientUDP::ModeCommande(){
    return EnvoyerCommande("command");
}


std::string TelloClientUDP::Decoller(){
    return EnvoyerCommande("takeoff");
}

std::string TelloClientUDP::Aterrir(){
    return EnvoyerCommande("land");
}

std::string TelloClientUDP::Monter(int cm){

    std::stringstream sst; sst<<cm;
    std::string cmd = "up " + sst.str();
    return EnvoyerCommande(cmd);

}

std::string TelloClientUDP::Descendre(int cm){

    std::stringstream sst; sst<<cm;
    std::string cmd = "down " + sst.str();
    return EnvoyerCommande(cmd);

}

std::string TelloClientUDP::Gauche(int cm){

    std::stringstream sst; sst<<cm;
    std::string cmd = "left " + sst.str();
    return EnvoyerCommande(cmd);

}

std::string TelloClientUDP::Droite(int cm){

    std::stringstream sst; sst<<cm;
    std::string cmd = "right " + sst.str();
    return EnvoyerCommande(cmd);
}

std::string TelloClientUDP::Avant(int cm){

    std::stringstream sst; sst<<cm;
    std::string cmd = "forward " + sst.str();
    return EnvoyerCommande(cmd);

}

std::string TelloClientUDP::Arriere(int cm){

    std::stringstream sst; sst<<cm;
    std::string cmd = "back " + sst.str();
    return EnvoyerCommande(cmd);

}

std::string TelloClientUDP::TournerHoraire(int deg){

    std::stringstream sst; sst<<deg;
    std::string cmd = "cw " + sst.str();
    return EnvoyerCommande(cmd);

}

std::string TelloClientUDP::TournerTrigo(int deg){

    std::stringstream sst; sst<<deg;
    std::string cmd = "ccw " + sst.str();
    return EnvoyerCommande(cmd);

}
