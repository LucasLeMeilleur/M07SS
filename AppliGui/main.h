﻿//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>

#include "TelloClientUDP.h"
#include "ThreadServ.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// Composants g�r�s par l'EDI
	TButton *ButDeg;
	TButton *ButFow;
	TTrackBar *TrackDeg;
	TBevel *BevelCmd;
	TBevel *BevelJoystick;
	TButton *ButLef;
	TButton *ButBack;
	TButton *ButRig;
	TButton *ButHorr;
	TTrackBar *TrackVitesse;
	TButton *ButUp;
	TTrackBar *TrackHauteur;
	TButton *ButDown;
	TButton *ButOff;
	TButton *ButLand;
	TButton *ButCmd;
	TEdit *EditIP;
	TLabel *LabelInfoCmd;
	TLabel *LabelDeg;
	TLabel *LabelVitesse;
	TLabel *LabelHauteur;
	TShape *ShapeJoy;
	TRichEdit *RichEdit1;
	TButton *ButDev;
	void __fastcall ButCmdClick(TObject *Sender);
	void __fastcall ButFowClick(TObject *Sender);
	void __fastcall ButBackClick(TObject *Sender);
	void __fastcall ButLefClick(TObject *Sender);
	void __fastcall ButRigClick(TObject *Sender);
	void __fastcall ButUpClick(TObject *Sender);
	void __fastcall ButDownClick(TObject *Sender);
	void __fastcall ButOffClick(TObject *Sender);
	void __fastcall ButLandClick(TObject *Sender);
	void __fastcall ButDegClick(TObject *Sender);
	void __fastcall ButHorrClick(TObject *Sender);
	void __fastcall TrackVitesseChange(TObject *Sender);
	void __fastcall TrackDegChange(TObject *Sender);
	void __fastcall TrackHauteurChange(TObject *Sender);

    void __fastcall BlockFormExceptButton(TButton *butt,TEdit *IP);
    void __fastcall UnblockForm();
	void __fastcall ShapeJoyMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall ShapeJoyMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall ShapeJoyMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall ButDevClick(TObject *Sender);

private:	// D�clarations utilisateur
	TelloClientUDP *TelloClient;
	int Vitesse, click;
	String CmdJoystick;
	int cmdX,cmdY;
	ThreadServ *ThreadServTello;

public:		// D�clarations utilisateur
	__fastcall TForm1(TComponent* Owner);


protected:

};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
