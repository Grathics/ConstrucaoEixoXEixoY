//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitConstrucaoXYZ.h"
#include "UnitDesenha3ds.h"
#include "UnitEixoXY.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
VetorDes3Ds  Desenho3D1(M_PI/2);
Desenho Desenho3DXY;
long double MMVetor1;
long double LMVetor1;
long double MAlpha1;
 long double LAlpha1;
long double BetaT1=M_PI/2;
bool Move1=false;
int Contador1=2;
int Cont;
int Contador1M=0;
long double MMVetor2[1000];
long double LMVetor2[1000];
long double MAlpha2[1000];
 long double LAlpha2[1000];
 long double MZo[1000];
 long double LZo[1000];
 int ContadorRecup=0;
 long double Ang;
 void Eixos1(TCanvas *);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
if (Form1->Visible){
Edit1->SetFocus();
}
Desenho3D=&Desenho3D1;



}
int EixoYo2(float zo, long double Alphat,float Betat,float MVetor){




  if (zo<=0) {
  zo=-zo;
		 return floor(MVetor*Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI+M_PI/2+Betat));
	 }


  return MVetor*Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI/2+Betat);



}

//---------------------------------------------------------------------------
void __fastcall TForm1::Edit1KeyPress(TObject *Sender, System::WideChar &Key)
{
 if (Key=='\r'){

 Edit2->SetFocus();

 }



}
//---------------------------------------------------------------------------





void __fastcall TForm1::Edit2KeyPress(TObject *Sender, System::WideChar &Key)
{
int kx;
int ky;
int kx1;
int ky1;


if (Key=='\r'){

  Edit3->SetFocus();

}
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button1Click(TObject *Sender)
{

int kx;
int ky;
int kx1;
int ky1;

int i;
i=Contador1%2;
int j=Form2->Contador;
long double xo=StrToFloat(Edit1->Text);
long double yo=StrToFloat(Edit2->Text);
long double zo=StrToFloat(Edit3->Text);

  if (i==0){

  Desenho3D->EixoXo2(xo,yo,&MAlpha1,&MMVetor1);

  EixoYo2(zo,MAlpha1,BetaT1,MMVetor1);

   Desenho3D->SetMAlpha(MAlpha1,Contador1M);
   Desenho3D->SetMMVetorG(MMVetor1,Contador1M);
   Desenho3D->SetMZo(zo,Contador1M) ;



   Label1->Caption="P:"+IntToStr(Contador1M)+"1 XYZ={"+FloatToStr(xo)+" , "+FloatToStr(yo)+" , "+FloatToStr(zo)+" }; �";
   Contador1++;
  }
  if (i==1){

   Desenho3D->EixoXo2(xo,yo,&LAlpha1,&LMVetor1);
   Desenho3D->EixoYo(zo,LAlpha1,BetaT1,LMVetor1);


   Desenho3D->SetLZo(zo,Contador1M);
   Desenho3D->SetLAlpha(LAlpha1,Contador1M);
   Desenho3D->SetLMVetorG(LMVetor1,Contador1M);





	Desenho3D->SetBetaT(M_PI/2);
	Label2->Caption="P:"+IntToStr(Contador1M)+"2 XYZ={"+FloatToStr(xo)+" , "+FloatToStr(yo)+" , "+FloatToStr(zo)+" }; �";
	Desenho3D->SetPosi1(Contador1M+1);

	 
	Form2->Contador++;
	Desenho3D->Posi1++;


   Contador1++;
   Contador1M=Contador1M+1;
  }


}






//---------------------------------------------------------------------------
void Desenhando(){







}
void __fastcall TForm1::Button2Click(TObject *Sender)
{
   long double BetaTDes=Desenho3D->GetBetaT();
   Desenho3D->Eixos1(Form1->Canvas);
  Desenho3D->Beta=Desenho3D->Beta +M_PI/50;
   Desenho3D->Desenha(Form1->Canvas);

}
//---------------------------------------------------------------------------




