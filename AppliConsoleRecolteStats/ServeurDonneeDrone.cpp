//---------------------------------------------------------------------------

#pragma hdrstop

#include "ServeurDonneeDrone.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

#include <sstream>
#include <iostream>

ServeurDonneeDrone::ServeurDonneeDrone(std::string pilote, std::string numeroDrone){
    fichierLog.open("serveur.log", std::ios_base::out);
    serveurUDP.OuvrirLaSocketDEcoute(8890, "0.0.0.0");
    DebuterJSON(pilote,numeroDrone);


}



void ServeurDonneeDrone::OuvrirFichierLog(std::string nomFichier){
    fichierLog.open("serveur.log", std::ios_base::app);

}

int nb = 0,increment=0;

void ServeurDonneeDrone::AjouterDonneesJSON(std::string message){

    std::string DataEncoded;

    DataEncoded = message;
    if(increment > 0){
        leJSON += ",\r";
    }

    increment++;
    int nb= 0,bn = 0;
    do{
        nb = DataEncoded.find('\n');
        bn = DataEncoded.find('\r');
        DataEncoded.erase(std::find(DataEncoded.begin(), DataEncoded.end(), '\n'));
        DataEncoded.erase(std::find(DataEncoded.begin(), DataEncoded.end(), '\r'));
    }while((nb != -1) && (bn != -1));

    if(DataEncoded.length() > 1)	DataEncoded.insert(0,"\t\t {\"");
    nb = 0;

    do{
        nb = DataEncoded.find(':', nb+3);
        if(nb != -1) DataEncoded.replace(nb,1,"\":\"");
     }while(nb != -1);

    nb = DataEncoded.rfind(';');
    if(nb != -1) DataEncoded.replace(nb,1,"\"}");
    nb = 0;

    do{
        nb = DataEncoded.find(';');
        if(nb != -1) DataEncoded.replace(nb,1,"\",\"");

    }while(nb != -1);

    nb = 1;
    fichierLog << DataEncoded;
    leJSON += DataEncoded;
    std::cout << DataEncoded << "\n";
}

void ServeurDonneeDrone::AjoutFichierLog(std::string texte){
    fichierLog << texte;
}

void ServeurDonneeDrone::FermerFichierLog(){
    fichierLog.close();

}

int ServeurDonneeDrone::RecevoirDonneesDrone(){

    std::string msg;   int nbOctets =0 ;
    nbOctets=serveurUDP.RecevoirUnMessage(msg, 1000000);
    if(nbOctets <= 0 ) return nbOctets;
    AjouterDonneesJSON(msg);
    fichierLog << msg;
    return nbOctets;

}

void ServeurDonneeDrone::DebuterJSON(std::string pilote, std::string numeroDrone){

    std::stringstream stimestand;
    int timestamp = (int)time(NULL);

    stimestand << timestamp;
    leJSON += "\n{\n\t\"donneesVol\": { \n\t\t\"nom\":\"LucasLeMeilleur\", \n\t\t\"numero\":\"1ZB0UB\", \n\t\t\"time\":\"";
    leJSON +=  stimestand.str();
    leJSON += "\", \n\t\t\"etats\":[\n";

}

void ServeurDonneeDrone::CloreJSON(){
    leJSON += "\r\t\t] \n\t} \n}\r";

    ofstream fichierJson;
    fichierJson.open("drone.json");
    fichierJson << leJSON;
    fichierJson.close();

}
