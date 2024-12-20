﻿//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "ThreadServ.h"
#include "main.h"
//---------------------------------------------------------------------------

//   Important : Les m�thodes et les propri�t�s des objets de la VCL peuvent seulement �tre
//   utilis�es dans une m�thode appel�e avec Synchronize, par exemple :
//
//      Synchronize(&UpdateCaption);
//
//   o� UpdateCaption pourrait ressembler � :
//
//
//---------------------------------------------------------------------------

__fastcall ThreadServ::ThreadServ(bool CreateSuspended)
	: TThread(CreateSuspended)
{
}
//---------------------------------------------------------------------------
void __fastcall ThreadServ::Execute(){
	TelloServeur = new ServeurDonneeDrone(AnsiString(Form1->EditIP->Text).c_str(),"T3ST1");

    TelloServeur->DebuterJSON("LucasLeMeilleur","EASY121");
	std:string DataDrone, tot;
	String DataAff;
	int n = 1;

	do{

		n = TelloServeur->RecevoirDonneesDrone(DataDrone);
		DataAff = UnicodeString(DataDrone.c_str());
		Form1->RichEdit1->Lines->Add(DataAff);

	}while(n > 0);

	TelloServeur->CloreJSON();
	Form1->RichEdit1->Lines->Add("Fichier drone.json crée");
}
//---------------------------------------------------------------------------

