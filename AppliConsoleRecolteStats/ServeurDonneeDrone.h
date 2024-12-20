//---------------------------------------------------------------------------

#ifndef ServeurDonneeDroneH
#define ServeurDonneeDroneH
//---------------------------------------------------------------------------
#endif

#include <fstream>
#include "IRServeurUDP.h"
#include <string>

class ServeurDonneeDrone{
    private:
        ofstream fichierLog;
        IRServeurUDP serveurUDP;
        std::string leJSON;

    public:
        ServeurDonneeDrone(std::string pilot, std::string numeroDrone);
        void OuvrirFichierLog(std::string nomFichier);
        void AjoutFichierLog(std::string texte);
        void FermerFichierLog();
        int RecevoirDonneesDrone();
        std::string CreerJSON(std::string pilote, std::string numeroDrone);
        void EnvoyerDonneesBDD(std::string IPREST, std::string urlREST);
        void DebuterJSON(std::string pilote, std::string numeroDrone);
        void AjouterDonneesJSON(std::string message);
        void CloreJSON();

};
