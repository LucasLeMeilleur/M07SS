//---------------------------------------------------------------------------

#ifndef TelloClientUDPH

#define TelloClientUDPH
//---------------------------------------------------------------------------
#endif

#include <string>
#include <cstring>
#include "IRClientUDP.h"


class TelloClientUDP{

	private:
    IRClientUDP client;

	public:
    TelloClientUDP();
    std::string EnvoyerCommande(std::string commande);
    std::string ModeCommande();
    std::string Decoller();
    std::string Aterrir();
    std::string Monter(int cm);
    std::string Descendre(int cm);
    std::string Droite(int cm);
    std::string Gauche(int cm);
    std::string Avant(int cm);
    std::string Arriere(int cm);
    std::string TournerHoraire(int deg);
    std::string TournerTrigo(int deg);

};