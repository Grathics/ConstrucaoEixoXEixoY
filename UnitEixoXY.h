//---------------------------------------------------------------------------

#ifndef UnitEixoXYH
#define UnitEixoXYH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TButton *Button7;
	TButton *Button8;
	TButton *Button9;
	TButton *Button10;
	TButton *Button11;
	TButton *Button12;
	TButton *Button13;
	TButton *Button14;
	TButton *Button15;
	TButton *Button16;
	TButton *Button17;
	TButton *Button18;
	TButton *Button19;
	TButton *Button20;
	TImage *Image1;
	TButton *Button21;
	TPanel *Panel1;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TButton *Button22;
	TButton *Button23;
	TTimer *Timer1;
	TLabel *Label1;
	TButton *Button24;
	TButton *Button25;
	TEdit *Edit1;
	TLabel *Label2;
	TPanel *Panel2;
	TCheckBox *CheckBox1;
	TPanel *Panel3;
	TRadioButton *RadioXoY;
	TRadioButton *RadioZoX;
	TLabel *Label3;
	TButton *Button26;
	TPanel *Panel4;
	TRadioButton *RXoY;
	TRadioButton *RZoX;
	TButton *Button27;
	TButton *Button28;
	TPanel *Panel5;
	TEdit *Edit2;
	TLabel *Label4;
	TRadioButton *Cancel;
	TPanel *Panel6;
	TRadioButton *BetaT0;
	TRadioButton *BetaTMPI2;
	TRadioButton *RadioButton3;
	TButton *ButtonSalvar;
	TButton *ButtonRecupera;
	TButton *ButtonAlpha;
	TButton *ButtonBeta;
	TImage *Image2;
	TButton *ButtonLimpa;
	TCheckBox *CheckBox2;
	TSaveDialog *SaveDialog1;
	TOpenDialog *OpenDialog1;
	TButton *Button29;
	TButton *Button30;
	TLabel *Label5;
	TPanel *Panel7;
	TButton *Button31;
	TButton *Button32;
	TButton *Button33;
	TButton *Button34;
	TPanel *Panel8;
	TLabel *Label6;
	TLabel *Label7;
	TButton *Close;
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall Button11Click(TObject *Sender);
	void __fastcall Button12Click(TObject *Sender);
	void __fastcall Button13Click(TObject *Sender);
	void __fastcall Button14Click(TObject *Sender);
	void __fastcall Button15Click(TObject *Sender);
	void __fastcall Button16Click(TObject *Sender);
	void __fastcall Button17Click(TObject *Sender);
	void __fastcall Button18Click(TObject *Sender);
	void __fastcall Button19Click(TObject *Sender);
	void __fastcall Button20Click(TObject *Sender);
	void __fastcall Button21Click(TObject *Sender);
	void __fastcall Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall Button22Click(TObject *Sender);
	void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall Button23Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Button24Click(TObject *Sender);
	void __fastcall Button25Click(TObject *Sender);
	void __fastcall Edit1DblClick(TObject *Sender);
	void __fastcall Button26Click(TObject *Sender);
	void __fastcall Button27Click(TObject *Sender);
	void __fastcall Button28Click(TObject *Sender);
	void __fastcall RadioZoXClick(TObject *Sender);
	void __fastcall RadioXoYClick(TObject *Sender);
	void __fastcall BetaT0Click(TObject *Sender);
	void __fastcall BetaTMPI2Click(TObject *Sender);
	void __fastcall ButtonSalvarClick(TObject *Sender);
	void __fastcall ButtonRecuperaClick(TObject *Sender);
	void __fastcall ButtonAlphaClick(TObject *Sender);
	void __fastcall ButtonBetaClick(TObject *Sender);
	void __fastcall ButtonLimpaClick(TObject *Sender);
	void __fastcall RadioButton1Click(TObject *Sender);
	void __fastcall Button29Click(TObject *Sender);
	void __fastcall Button30Click(TObject *Sender);
	void __fastcall Button31Click(TObject *Sender);
	void __fastcall Button33Click(TObject *Sender);
	void __fastcall Button32Click(TObject *Sender);
	void __fastcall Button34Click(TObject *Sender);
	void __fastcall CloseClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
