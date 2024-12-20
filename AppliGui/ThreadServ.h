//---------------------------------------------------------------------------

#ifndef ThreadServH
#define ThreadServH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>

#include "ServeurDonneeDrone.h"
//---------------------------------------------------------------------------
class ThreadServ : public TThread
{
private:
	ServeurDonneeDrone *TelloServeur;

protected:
	void __fastcall Execute();

public:
	__fastcall ThreadServ(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
