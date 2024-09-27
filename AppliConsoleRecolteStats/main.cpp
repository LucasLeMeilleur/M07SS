#include <iostream>
#include <tchar.h>
#include "IRServeurUDP.h"
#include <string>
#include <fstream>
#include <stdio.h>
#include <sstream>


int main(){

    IRServeurUDP Server;
    std::string Data,DataEncoded, DataEncConc, DataFinal, Entete, Pied;
    Server.OuvrirLaSocketDEcoute(8890, "0.0.0.0");

    std::ofstream Log("serveur.log", std::ios_base::app);
    std::ofstream JSON("drone.json", std::ios_base::app);

    struct Stats{
		int pitch,roll,yaw,vgx,vgy,vgz,templ,temph,tof,h,bat,time;
        float baro,agx,agy,agz;
    };

    Stats StatDrone;


    std::stringstream stimestand;

    int timestamp = (int)time(NULL);

    stimestand << timestamp;
    JSON << "\n{\n\t\"donneesVol\": { \n\t\t\"nom\":\"LucasLeMeilleur\", \n\t\t\"numero\":\"1ZB0UB\", \n\t\t\"time\":\"";
    JSON <<  stimestand;
    JSON <<  "\", \n\t\t\"etats\":[\n";



    int nb = 0;
    unsigned long int increment=0;

    do{
        nb = Server.RecevoirUnMessage(Data, 3000000);

        DataEncoded = Data;


        if (nb < 0) {
        	break;
        }


        if(increment > 0){
            JSON<< ",\r";
        }

        increment++;

//        std::sscanf (Data.c_str(), "pitch:%d;roll:%d;yaw:%d;vgx:%d;vgy:%d;vgz:%d;templ:%d;temph:%d;tof:%d;h:%d;bat:%d;baro:%f;time:%d;agx:%f;agy:%f;agz:%f;",
//        &StatDrone.pitch,&StatDrone.roll,&StatDrone.yaw,&StatDrone.vgx,&StatDrone.vgy,&StatDrone.vgz,&StatDrone.templ,&StatDrone.temph,&StatDrone.tof,
//        &StatDrone.bat,&StatDrone.baro,&StatDrone.time,&StatDrone.agx,&StatDrone.agy,&StatDrone.agz);


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


       	Log << DataEncoded;
        JSON << DataEncoded;



    }while(nb >0);





    JSON << "\r\t\t] \n\t} \n}\r";


    Log.close();
    JSON.close();

}
