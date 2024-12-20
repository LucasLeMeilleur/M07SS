//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"


TForm1 *Form1;

//---------------------------------------------------------------------------


void __fastcall TForm1::BlockFormExceptButton(TButton *butt, TEdit *IP){
	for (int i = 0; i < this->ControlCount; i++){
		TControl* control = this->Controls[i];
		if (control != butt){
			control->Enabled = false;
		}
	}
    TForm1::EditIP->Enabled = true;

}


void __fastcall TForm1::UnblockForm()
{
	for (int i = 0; i < this->ControlCount; i++){
		this->Controls[i]->Enabled = true;
    }
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

	ThreadServTello = NULL;
	TForm1::Width = 770;
	BlockFormExceptButton(ButCmd, EditIP);
}
//---------------------------------------------------------------------------




void __fastcall TForm1::ButCmdClick(TObject *Sender)
{

	TelloClient = new TelloClientUDP(AnsiString(EditIP->Text).c_str());
	TelloClient->ModeCommande();
	LabelInfoCmd->Caption = "command";
	UnblockForm();
	if(ThreadServTello != NULL){
		   ThreadServTello->Terminate();
		   ThreadServTello->WaitFor();
		   delete ThreadServTello;
		   ThreadServTello = NULL;
    }
	ThreadServTello = new ThreadServ(true);
	ThreadServTello->Start();

	TelloClient->EnvoyerCommande("streamon");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButFowClick(TObject *Sender)
{
	TelloClient->Avant(50);

	LabelInfoCmd->Caption = "forward 50";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButBackClick(TObject *Sender)
{
	TelloClient->Arriere(50);

	LabelInfoCmd->Caption = "backward 50";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButLefClick(TObject *Sender)
{
	TelloClient->Gauche(50);

	LabelInfoCmd->Caption = "left 50";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButRigClick(TObject *Sender)
{
	TelloClient->Droite(50);

	LabelInfoCmd->Caption = "right 50";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButUpClick(TObject *Sender)
{
	TelloClient->Monter(TrackHauteur->Position);
	LabelInfoCmd->Caption = "up " + (String)TrackHauteur->Position;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButDownClick(TObject *Sender)
{
	TelloClient->Descendre(TrackHauteur->Position);
	LabelInfoCmd->Caption = "down " + (String)TrackHauteur->Position;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButOffClick(TObject *Sender)
{
	TelloClient->Decoller();
	LabelInfoCmd->Caption = "takeoff";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButLandClick(TObject *Sender)
{
	TelloClient->Atterrir();
	LabelInfoCmd->Caption = "land";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButDegClick(TObject *Sender)
{
	TelloClient->TournerTrigo(TrackDeg->Position);
	LabelInfoCmd->Caption = "ccw "+ (String)TrackDeg->Position;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButHorrClick(TObject *Sender)
{
	TelloClient->TournerHoraire(TrackDeg->Position);
	LabelInfoCmd->Caption = "cw " + (String)TrackDeg->Position;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TrackVitesseChange(TObject *Sender)
{
	Vitesse = TrackVitesse->Position;
	LabelVitesse->Alignment = taCenter;
	LabelVitesse->Caption = (String)TrackVitesse->Position + " cm/s";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TrackDegChange(TObject *Sender)
{
	LabelDeg->Caption = (String)TrackDeg->Position + " deg";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TrackHauteurChange(TObject *Sender)
{
	LabelHauteur->Caption = (String)TrackHauteur->Position + " cm";
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ShapeJoyMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	click = 0;

	TelloClient->DeplacerXYZ(cmdX,cmdY,0,TrackVitesse->Position);

	ShapeJoy->Top = 293;
	ShapeJoy->Left = 573;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ShapeJoyMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	click = 1;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ShapeJoyMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
	int haut = ShapeJoy->Top+Y - ShapeJoy->Height/2;
	int gauche = ShapeJoy->Left+X - ShapeJoy->Width/2;
	if (click && gauche>BevelJoystick->Left
			  && haut>BevelJoystick->Top
			  && gauche+ShapeJoy->Width<BevelJoystick->Left+BevelJoystick->Width
			  && haut+ShapeJoy->Height<BevelJoystick->Top+BevelJoystick->Height) {
		ShapeJoy->Top= haut;
		ShapeJoy->Left= gauche;

		int Hauteur = (ShapeJoy->Top-145) * 1000 / 296 ;
		int Gauche = (ShapeJoy->Left-425) * 1000 / 296;

		cmdY = (Hauteur-500);
		cmdX = (Gauche-500);


		String commandeFinale = "go "+ (String)(Hauteur-500) + " " + (String)(Gauche-500) + " 0 " + (String)TrackVitesse->Position;



		LabelInfoCmd->Caption = (commandeFinale);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButDevClick(TObject *Sender)
{
	if(TForm1::Width == 1120){
		TForm1::Width = 770;
		this->Caption = ">>";
	}else if(TForm1::Width == 770) {
		TForm1::Width = 1120;
		this->Caption = "<<";
	}
}
//---------------------------------------------------------------------------


