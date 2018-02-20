//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#include "UnitEixoXY.h"
#include "UnitArquivo.h"
#include <fstream>
#include <string.h>
#include <math.h>

using std::string;
using std::ostream;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
long double LMVetorG[1000];
int kx1=0;
int ky1=0;
int kx1z=0;
int ky1z=0;
float kx;
float ky;
int Kx=900;
int Ky=500;
int KxO;
int KxOO=900;
int KyOO=500;
int Contar=0;
bool g=true;
 TPoint P[10];
 int Lkx[1000];
 int Lkxz[1000];
 int Lky[1000];
 int Lkyz[1000];
 int Mkx[1000];
 int Mkxz[1000];
 int Mky[1000];
 int Mkyz[1000];
 TColor p[1000];
 int Contador=0;
 bool Move=false;
float Alpha[100];
float *Beta=new float[100];
float Teta=0;
long double MVetorG[100];
long double AlphaT=0;
 float BetaT=M_PI/2;
int Y (int y);
int X (int x);
float *MPIA=new float[100];
float EixoX(float xo,float yo,float zo,long double *Alphat,long double *Betat,float Tetat,float *MVetor);
float EixoY(float xo,float yo,float zo, long double *Alphat,long double Betat,float Tetat,float MVetor);

void Cubo(float Lado);
void Limpa1();
void Cubo1(TCanvas IMG,float Lado );
int EixoXo(long double xo,long double yo,float zo,  long double *Alphat,long double *MVetorXY);
int OX(float x);
int OY(float y);
void LimpaZoX(TCanvas *);
void Colorido(TCanvas *,int );
void RedesenhaDesloca(TCanvas *);
void LimpaRedesenhaDesloca(TCanvas *);
 float LAlpha[1000];
 float MAlpha[1000];
long double MMVetorG[1000];
TCanvas *Canvas1;

int Zo[1000];
int MZo[1000];
int LZo[1000];
int MYo[1000];
int LYo[1000];
int Yo[1000];
int LMkx[1000];
int LLkx[1000];
int LMky[1000];
int LLky[1000];
int LBMkx[1000];
int LBLkx[1000];
int LBMky[1000];
int LBLky[1000];

Desenho Desenho3DS;
void LimpaDesenho3DS(TCanvas *);
void MLimpaB(TCanvas *);
void GravaArquivo();
void RecebeUnicode(char *,UnicodeString);
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void RecebeUnicode(char *File,UnicodeString FileEnter){
  int i=0;
  string Str;
  for (i=0;i<FileEnter.Length();i++){
  Str[i]=FileEnter[i];


  }

}

int OX(float x){

return	floor(x-Kx);

}
int OXDes(int x){

return	KxOO+x;

}
int OY(float y){
  return floor(Ky-y);
}
int OYDes(int y){
  return KyOO-y;
}
 int X(int x){
return x+Kx;
   }

   int Y(int y){
return Ky-y;
   }
   float RotaX(float x1,float y1, float Teta){



	return  x1*Cos(Teta)-y1*Sin(Teta);





}
//RotaY segue o mesmo que RotaX porem a transforma��o ocorre para a coordenada yo;
float RotaY(float x1,float y1, float Teta){



	return  x1*Sin(Teta)+y1*Cos(Teta);




}
float EixoX(float xo,float yo,float zo,  float *Alphat,long double *Betat,float Tetat,float *MVetorXY){
float MXYVetor;

float MVetorXY1;
float Alphat1=0;






MVetorXY1=Sqrt((xo*xo) +(yo*yo));

MXYVetor=MVetorXY1;


 *MVetorXY=MVetorXY1;

   if (xo==0) {
	if (yo>0){
	  *Alphat=M_PI/2;
  Alphat1=asin(1.0);
  return 0;

	}
	 if (yo<0) {
	   *Alphat=M_PI+M_PI/2;
  Alphat1=asin(-1.0);
  return 0;
	 }

}else{

	  if (yo==0) {
		 Alphat1=acos(xo/MVetorXY1);

	  }

	  if ((xo<0)&&(yo<0)) {
		 xo=-xo;
		 Alphat1=acos(xo/MVetorXY1)+M_PI;
		 xo=-xo;


	  }


   if ((xo<0)&&(yo>0)) {
		xo=-xo;

			Alphat1=M_PI-acos(xo/MVetorXY1);

		xo=-xo;
   }

	 if ((xo>0)&&(yo<0)) {
		 Alphat1=2*M_PI-acos(xo/MVetorXY1);

	 }
	 if ((xo>0)&&(yo>0)) {
		 Alphat1=acos(xo/MVetorXY1);

	 }

	  }

	 if (MVetorXY1<=0) {
	   *MVetorXY=0;
	   return 0;
		}
	*Alphat=Alphat1;
   return  MXYVetor*Cos(Alphat1);





}
int EixoY(float xo,float yo,float zo, long double Alphat,long double Betat,float Tetat,long double MVetor){


long double MXYVetor;
long double MZYVetor;

 MXYVetor=Sqrt(xo*xo+yo*yo);
 MZYVetor=Sqrt(zo*zo+yo*yo);
  if (zo<0) {
  zo=-zo;
		 return MVetor*Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI+M_PI/2+Betat);
	 }

   float truncado = floor(MVetor*Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI/2+Betat) ) ;

  return truncado;



}
int EixoXo(long double xo,long double yo,float zo,  long double *Alphat,long double *MVetorXY){

long double MXYVetor;

long double MVetorXY1;
long double Alphat1=0;






MVetorXY1=Sqrt((xo*xo) +(yo*yo));
if (MVetorXY1==0){

MVetorXY1=1;

}

MXYVetor=MVetorXY1;


 *MVetorXY=MVetorXY1;

   if (xo==0) {
	if (yo>0){
	  *Alphat=M_PI/2;
  Alphat1=asin(1.0);
  return 0;

	}
	 if (yo<0) {
	   *Alphat=M_PI+M_PI/2;
  Alphat1=asin(-1.0);
  return 0;
	 }

}else{

	  if (yo==0) {

		 Alphat1=acos(xo/MVetorXY1);

	  }

	  if ((xo<0)&&(yo<0)) {
		 xo=-xo;

		 Alphat1=acos(xo/MVetorXY1)+M_PI;
		 xo=-xo;



	  }


   if ((xo<0)&&(yo>0)) {
		xo=-xo;

			Alphat1=M_PI-acos(xo/MVetorXY1);

		xo=-xo;
   }

	 if ((xo>0)&&(yo<0)) {
		 Alphat1=2*M_PI-acos(xo/MVetorXY1);

	 }
	 if ((xo>0)&&(yo>0)) {
		 Alphat1=acos(xo/MVetorXY1);

	 }

	  }

	 if (MVetorXY1<=0) {
	   *MVetorXY=0;
	   return 0;
		}
	*Alphat=Alphat1;
   return floor( MXYVetor*Cos(Alphat1));



}
int EixoYo(float zo, long double Alphat,float Betat,float MVetor){




  if (zo<=0) {
  zo=-zo;
		 return floor(MVetor*Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI+M_PI/2+Betat));
	 }


  return MVetor*Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI/2+Betat);



}
float EixoYM( float Alphat,float Betat,float Tetat, float MVetort){




  return MVetort*Sin(Alphat)*Sin(Betat)+MVetort*Sin(M_PI/2+Betat);;


}
float EixoXM(float Alphat,float Betat,float Tetat,float MVetort){




   return  MVetort*Cos(Alphat);








}
 float EixoXMX(float yo,float Alphat,float Betat,float Tetat,float MVetort){



   return  MVetort*Cos(Alphat);








}
float EixoXMo(long double Alphat,long double MVetort){

	return  MVetort*Cos(Alphat);

}
int EixoYMY( float yo,float Alphat,float Betat,float Tetat, float MVetort){


  return MVetort*Sin(Alphat)*Sin(Betat);


}
 float EixoYMY2( float yo,float zo,float Alphat,float Betat,float Tetat, float MVetort){

	 if ((zo<0)&&(yo<0)) {
	 zo=-zo;
		 return -(MVetort*Sin(Alphat)*Sin(Betat)+(zo*Sin(M_PI/2+Betat)));
	 }

	if(yo<0){

   return MVetort*Sin(-Alphat)*Sin(Betat)+zo*Sin(M_PI/2+Betat);


   }
   }

float EixoYMY3( float yo,float zo,float Alphat,float Betat,float Tetat, float MVetort){



	  if (zo<0) {
	  zo=-zo;
	  return MVetort *Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI+M_PI/2+Betat);
	  }


  return MVetort *Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI/2+Betat);


}
int EixoYMo(float zo,float Alphat,float Betat, float MVetort){



	  if (zo<=0) {
	  zo=-zo;
	  return MVetort *Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI+M_PI/2+Betat);
	  }


  return MVetort *Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI/2+Betat);


}
void MLimpa1(TCanvas *h){
 int i=0;
int kx=0;
int ky=0;
TPoint MP[2];

Form2->Image1->Canvas->Pen->Color=clWhite;

  Form2->Image1->Canvas->Pen->Width=1;

 if (Form2->RZoX->Checked) {


 for (i = 0; i < Contador; i++) {

MP[0].x= Mkx[i];
  MP[0].y=Mky[i];
  MP[1].x= Lkx[i];
  MP[1].y=Lky[i];


  Form2->Image1->Canvas->Polyline(MP,1);

  }

  }

  if (Form2->RXoY->Checked) {


  for (i = 0; i < Contador; i++) {
MP[0].x= LBMkx[i];
  MP[0].y= LBMky[i];
 MP[1].x=LBLkx[i];
  MP[1].y=  LBLky[i];


  Form2->Image1->Canvas->Polyline(MP,1);
  }
  }
 Form2->Image1->Canvas->Pen->Width=1;
}
void Limpa1(){
 float kx=0;
 float ky=0;

Form2->Canvas->Pen->Color=clWhite;
kx=EixoXMX(0,Alpha[0],Beta[0],Teta,MVetorG[0]);
ky=EixoYMY3(0,0,Alpha[0],Beta[0],Teta,MVetorG[0]);

Form2->Canvas->MoveTo(X(kx),Y(ky));
 kx=EixoXMX(0,Alpha[1],Beta[1],Teta,MVetorG[1]);
ky=EixoYMY3(-150,0,Alpha[1],Beta[1],Teta,MVetorG[1]);

Form2->Canvas->LineTo(X(kx),Y(ky));

 kx=EixoXMX(0,Alpha[2],Beta[2],Teta,MVetorG[2]);
ky=EixoYMY3(-150,0,Alpha[2],Beta[2],Teta,MVetorG[2]);

Form2->Canvas->LineTo(X(kx),Y(ky));
 kx=EixoXMX(0,Alpha[3],Beta[3],Teta,MVetorG[3]);
ky=EixoYMY3(150,0,Alpha[3],Beta[3],Teta,MVetorG[3]);

Form2->Canvas->LineTo(X(kx),Y(ky));
 kx=EixoXMX(0,Alpha[4],Beta[4],Teta,MVetorG[4]);
ky=EixoYMY3(-150,0,Alpha[4],Beta[4],Teta,MVetorG[4]);

Form2->Canvas->LineTo(X(kx),Y(ky));

  kx=EixoXMX(0,Alpha[5],Beta[5],Teta,MVetorG[5]);
ky=EixoYMY3(-150,300,Alpha[5],Beta[5],Teta,MVetorG[5]);

Form2->Canvas->LineTo(X(kx),Y(ky));
 kx=EixoXMX(0,Alpha[6],Beta[6],Teta,MVetorG[6]);
ky=EixoYMY3(-150,300,Alpha[6],Beta[6],Teta,MVetorG[6]);

Form2->Canvas->LineTo(X(kx),Y(ky));
kx=EixoXMX(0,Alpha[7],Beta[7],Teta,MVetorG[7]);
ky=EixoYMY3(-150,0,Alpha[7],Beta[7],Teta,MVetorG[7]);

Form2->Canvas->LineTo(X(kx),Y(ky));
 kx=EixoXMX(0,Alpha[8],Beta[8],Teta,MVetorG[8]);
ky=EixoYMY3(-150,0,Alpha[8],Beta[8],Teta,MVetorG[8]);

Form2->Canvas->MoveTo(X(kx),Y(ky));

  kx=EixoXMX(0,Alpha[9],Beta[9],Teta,MVetorG[9]);
ky=EixoYMY3(-150,300,Alpha[9],Beta[9],Teta,MVetorG[9]);

Form2->Canvas->LineTo(X(kx),Y(ky));
   kx=EixoXMX(0,Alpha[10],Beta[10],Teta,MVetorG[10]);
ky=EixoYMY3(-150,300,Alpha[10],Beta[10],Teta,MVetorG[10]);

Form2->Canvas->LineTo(X(kx),Y(ky));
 kx=EixoXMX(0,Alpha[11],Beta[11],Teta,MVetorG[11]);
ky=EixoYMY3(-150,300,Alpha[11],Beta[11],Teta,MVetorG[11]);

Form2->Canvas->MoveTo(X(kx),Y(ky));
kx=EixoXMX(0,Alpha[12],Beta[12],Teta,MVetorG[12]);
ky=EixoYMY3(-150,300,Alpha[12],Beta[12],Teta,MVetorG[12]);

Form2->Canvas->LineTo(X(kx),Y(ky));
kx=EixoXMX(0,Alpha[13],Beta[13],Teta,MVetorG[13]);
ky=EixoYMY3(-150,0,Alpha[13],Beta[13],Teta,MVetorG[13]);

Form2->Canvas->LineTo(X(kx),Y(ky));
kx=EixoXMX(0,Alpha[14],Beta[14],Teta,MVetorG[14]);
ky=EixoYMY3(-150,300,Alpha[14],Beta[14],Teta,MVetorG[14]);

Form2->Canvas->MoveTo(X(kx),Y(ky));
kx=EixoXMX(0,Alpha[15],Beta[15],Teta,MVetorG[15]);
ky=EixoYMY3(-150,300,Alpha[15],Beta[15],Teta,MVetorG[15]);

Form2->Canvas->LineTo(X(kx),Y(ky));



}
void LimpaCubo1(TCanvas *Img,float Lado){

 float kx=0;
float ky=0;

kx=EixoXMo(Alpha[0],MVetorG[0]);
ky=EixoYMo(-Lado/2,Alpha[0],BetaT,MVetorG[0]);

Img->MoveTo(X(kx),Y(ky));
 kx=EixoXMo(Alpha[1],MVetorG[1]);
ky=EixoYMo(-Lado/2,Alpha[1],BetaT,MVetorG[1]);
Img->Pen->Color=clWhite;
 Img->LineTo(X(kx),Y(ky));

 kx=EixoXMo(Alpha[2],MVetorG[2]);
ky=EixoYMo(-Lado/2,Alpha[2],BetaT,MVetorG[2]);

Img->LineTo(X(kx),Y(ky));


 kx=EixoXMo(Alpha[3],MVetorG[3]);
ky=EixoYMo(-Lado/2,Alpha[3],BetaT,MVetorG[3]);

Img->LineTo(X(kx),Y(ky));

 kx=EixoXMo(Alpha[4],MVetorG[4]);
ky=EixoYMo(-Lado/2,Alpha[4],BetaT,MVetorG[4]);

Img->LineTo(X(kx),Y(ky));


 kx=EixoXMo(Alpha[5],MVetorG[5]);
ky=EixoYMo(Lado/2,Alpha[5],BetaT,MVetorG[5]);

Img->LineTo(X(kx),Y(ky));




}
void Limpa2(){
TRect P= TRect(0,0,1000,1000);

Form2->Canvas->FillRect(P) ;
Form2->Canvas->Brush->Color=clWhite;
}
void Colorido(TCanvas *h,int i){

int  j;
j=i%7;

if (j==0){
h->Pen->Color=clGreen;

}
if(j==1){

h->Pen->Color=clYellow;
}
if (j==2){

h->Pen->Color=clLime;
}
if (j==3){
 h->Pen->Color=clPurple;

}
if (j==4){
h->Pen->Color=clRed;
}

if (j==5){

h->Pen->Color=clBlue;

}
if (j==6){

h->Pen->Color=clGray;
}







}
void Redesenha(TCanvas *h){
int i=0;
int kx=0;
int ky=0;
TPoint MP[2];
bool g=false;
p[0]=clGreen;
p[1]=clBlue;
p[2]=clYellow;
p[3]=clRed;
 float BetaTDes= BetaT;
 if (g){
 if (Form2->BetaTMPI2->Checked){
   BetaTDes=M_PI/2;
 }
 if (Form2->BetaT0->Checked){
   BetaTDes=0.0;
 }
 }



 Form2->Image1->Canvas->Pen->Width=1;
for (i = 4; i < 100; i++) {
  p[i]=clBlack;
}





   for (i = 0; i < Contador; i++) {
  kx=EixoXMo(MAlpha[i],MMVetorG[i]);
  ky=EixoYMo(MZo[i],MAlpha[i],BetaTDes,MMVetorG[i]);
  LBMkx[i]=X(kx);
  LBMky[i]=Y(ky);
  MP[0].x= LBMkx[i];
  MP[0].y= LBMky[i];

  kx=EixoXMo(LAlpha[i],LMVetorG[i]);
  ky=EixoYMo(LZo[i],LAlpha[i],BetaTDes,LMVetorG[i]);

  LBLkx[i]= X(kx);
  LBLky[i]=Y(ky);
  MP[1].x=LBLkx[i];
  MP[1].y=  LBLky[i];

  Colorido(Form2->Image1->Canvas,i );
   Form2->Image1->Canvas->Polyline(MP,1);





   }

}
void LimpaRedesenhaDesloca(TCanvas *h){
int i=0;
int kx;
int ky;
int kx1;
int ky1;
float LBMkx[1000];
float LBMky[1000];
float LBLkx[1000];
float  LBLky[1000];

TPoint MP[2];
bool g=false;
p[0]=clGreen;
p[1]=clBlue;
p[2]=clYellow;
p[3]=clRed;
 float BetaTDes= BetaT;
 if (g){
 if (Form2->BetaTMPI2->Checked){
   BetaTDes=M_PI/2;
 }
 if (Form2->BetaT0->Checked){
   BetaTDes=0.0;
 }
 }



 Form2->Image1->Canvas->Pen->Width=1;






   for (i = 0; i < Contador; i++) {
  kx=EixoXMo(MAlpha[i],MMVetorG[i]);
  ky=EixoYMo(MZo[i],MAlpha[i],BetaTDes,MMVetorG[i]);


  LBMkx[i]=OXDes(kx);
  LBMky[i]=OYDes(ky);
  MP[0].x= LBMkx[i];
  MP[0].y= LBMky[i];

  kx1=EixoXMo(LAlpha[i],LMVetorG[i]);
  ky1=EixoYMo(LZo[i],LAlpha[i],BetaTDes,LMVetorG[i]);

  LBLkx[i]= OXDes(kx1);
  LBLky[i]=OYDes(ky1);
  MP[1].x=LBLkx[i];
  MP[1].y=  LBLky[i];

  Form2->Image1->Canvas->Pen->Color=clWhite;
   Form2->Image1->Canvas->MoveTo(OXDes(kx),OYDes(ky));
	Form2->Image1->Canvas->LineTo(OXDes(kx1),OYDes(ky1));





   }

}
void RedesenhaDesloca(TCanvas *h){
int i=0;
int kx;
int ky;
int kx1;
int ky1;
float LBMkx[1000];
float LBMky[1000];
float LBLkx[1000];
float  LBLky[1000];

TPoint MP[2];
bool g=false;
p[0]=clGreen;
p[1]=clBlue;
p[2]=clYellow;
p[3]=clRed;
 float BetaTDes= BetaT;
 if (g){
 if (Form2->BetaTMPI2->Checked){
   BetaTDes=M_PI/2;
 }
 if (Form2->BetaT0->Checked){
   BetaTDes=0.0;
 }
 }



 Form2->Image1->Canvas->Pen->Width=1;
for (i = 4; i < 100; i++) {
  p[i]=clBlack;
}





   for (i = 0; i < Contador; i++) {
  kx=EixoXMo(MAlpha[i],MMVetorG[i]);
  ky=EixoYMo(MZo[i],MAlpha[i],BetaTDes,MMVetorG[i]);


  LBMkx[i]=OXDes(kx);
  LBMky[i]=OYDes(ky);
  MP[0].x= LBMkx[i];
  MP[0].y= LBMky[i];

  kx1=EixoXMo(LAlpha[i],LMVetorG[i]);
  ky1=EixoYMo(LZo[i],LAlpha[i],BetaTDes,LMVetorG[i]);

  LBLkx[i]= OXDes(kx1);
  LBLky[i]=OYDes(ky1);
  MP[1].x=LBLkx[i];
  MP[1].y=  LBLky[i];

   Colorido(Form2->Image1->Canvas,i );
   Form2->Image1->Canvas->MoveTo(OXDes(kx),OYDes(ky));
	Form2->Image1->Canvas->LineTo(OXDes(kx1),OYDes(ky1));





   }

}
void RedesenhaZoX(TCanvas *h){
int i=0;
int kx=0;
int ky=0;
TPoint MP[2];
g=false;
p[0]=clGreen;
p[1]=clBlue;
p[2]=clYellow;
p[3]=clRed;
float BetaTDes;

 Form2->Image1->Canvas->Pen->Width=1;
 if (Form2->RZoX->Checked){
	  BetaTDes=0;
for (i = 4; i < 100; i++) {
  p[i]=clBlack;
}





   for (i = 0; i < Contador; i++) {
  kx=EixoXMo(MAlpha[i],MMVetorG[i]);
  ky=EixoYMo(MZo[i],MAlpha[i],BetaTDes,MMVetorG[i]);
  LBMkx[i]=X(kx);
  LBMky[i]=Y(ky);
  MP[0].x= LBMkx[i];
  MP[0].y= LBMky[i];

  kx=EixoXMo(LAlpha[i],LMVetorG[i]);
  ky=EixoYMo(LZo[i],LAlpha[i],BetaTDes,LMVetorG[i]);

  LBLkx[i]= X(kx);
  LBLky[i]=Y(ky);
  MP[1].x=LBLkx[i];
  MP[1].y=  LBLky[i];

   Colorido(Form2->Image1->Canvas,i );
   Form2->Image1->Canvas->Polyline(MP,1);





   }
 }

  if (Form2->RXoY->Checked){
	  BetaTDes=M_PI/2;
for (i = 4; i < 100; i++) {
  p[i]=clBlack;
}





   for (i = 0; i < Contador; i++) {
  kx=EixoXMo(MAlpha[i],MMVetorG[i]);
  ky=EixoYMo(MZo[i],MAlpha[i],BetaTDes,MMVetorG[i]);
  LBMkx[i]=X(kx);
  LBMky[i]=Y(ky);
  MP[0].x= LBMkx[i];
  MP[0].y= LBMky[i];

  kx=EixoXMo(LAlpha[i],LMVetorG[i]);
  ky=EixoYMo(LZo[i],LAlpha[i],BetaTDes,LMVetorG[i]);

  LBLkx[i]= X(kx);
  LBLky[i]=Y(ky);
  MP[1].x=LBLkx[i];
  MP[1].y=  LBLky[i];

  Form2->Image1->Canvas->Pen->Color=p[i];
   Form2->Image1->Canvas->Polyline(MP,1);





   }
 }


}
void Cubo(float Lado){
float kx;
float ky;


}

void CuboBeta(float Lado){

  float kx;
float ky;
Form2->Canvas->Pen->Color=clRed;
kx=EixoXMX(-Lado/2,Alpha[0],Beta[0],Teta,MVetorG[0]);
ky=EixoYMY2(-Lado/2,0,Alpha[0],Beta[0],Teta,MVetorG[0]);

Form2->Canvas->MoveTo(X(kx),Y(ky));
 kx=EixoXMX(-Lado/2,Alpha[1],Beta[1],Teta,MVetorG[1]);
ky=EixoYMY2(-Lado/2,0,Alpha[1],Beta[1],Teta,MVetorG[1]);

Form2->Canvas->LineTo(X(kx),Y(ky));

 kx=EixoXMX(Lado/2,Alpha[2],Beta[2],Teta,MVetorG[2]);
ky=EixoYMY2(Lado/2,0,Alpha[2],Beta[2],Teta,MVetorG[2]);
Form2->Canvas->Pen->Color=clBlue;
 Form2->Canvas->LineTo(X(kx),Y(ky));
  kx=EixoXMX(Lado/2,Alpha[3],Beta[3],Teta,MVetorG[3]);
ky=EixoYMY2(Lado/2,0,Alpha[3],Beta[3],Teta,MVetorG[3]);
Form2->Canvas->Pen->Color=clYellow;
Form2->Canvas->LineTo(X(kx),Y(ky));
 kx=EixoXMX(-Lado/2,Alpha[4],Beta[4],Teta,MVetorG[4]);
ky=EixoYMY2(-Lado/2,0,Alpha[4],Beta[4],Teta,MVetorG[4]);
Form2->Canvas->Pen->Color=clLime;
 Form2->Canvas->LineTo(X(kx),Y(ky));





}

void CuboAlpha(float Lado){


   float kx;
float ky;
Form2->Canvas->Pen->Color=clRed;
kx=EixoXMX(-Lado/2,Alpha[0],Beta[0],Teta,MVetorG[0]);
ky=EixoYMY2(-Lado/2,0,Alpha[0],Beta[0],Teta,MVetorG[0]);

Form2->Canvas->MoveTo(X(kx),Y(ky));
 kx=EixoXMX(-Lado/2,Alpha[1],Beta[1],Teta,MVetorG[1]);
ky=EixoYMY2(-Lado/2,0,Alpha[1],Beta[1],Teta,MVetorG[1]);

Form2->Canvas->LineTo(X(kx),Y(ky));

 kx=EixoXMX(Lado/2,Alpha[2],Beta[2],Teta,MVetorG[2]);
ky=EixoYMY2(Lado/2,0,Alpha[2],Beta[2],Teta,MVetorG[2]);
Form2->Canvas->Pen->Color=clBlue;
 Form2->Canvas->LineTo(X(kx),Y(ky));
  kx=EixoXMX(Lado/2,Alpha[3],Beta[3],Teta,MVetorG[3]);
ky=EixoYMY2(Lado/2,0,Alpha[3],Beta[3],Teta,MVetorG[3]);
 Form2->Canvas->Pen->Color=clYellow;
Form2->Canvas->LineTo(X(kx),Y(ky));
 kx=EixoXMX(-Lado/2,Alpha[4],Beta[4],Teta,MVetorG[4]);
ky=EixoYMY2(-Lado/2,0,Alpha[4],Beta[4],Teta,MVetorG[4]);
Form2->Canvas->Pen->Color=clLime;
 Form2->Canvas->LineTo(X(kx),Y(ky));





}
void Cubo1(TCanvas *Img,float Lado){
long double kx=0;
long double ky=0;




}
void Eixos(TCanvas *p){
long double kx;
long double ky;
long double Ang;
long double Mtar;
Form2->Image1->Canvas->Pen->Color=clBlack;
kx=EixoXo(-1000.0,0.0,0.0,&Ang,&Mtar);
ky=EixoYo(0.0,Ang,M_PI/2,Mtar);
p->MoveTo(X(kx),Y(ky));
kx=EixoXo(2000.0,0.0,0.0,&Ang,&Mtar);
ky=EixoYo(0.0,Ang,M_PI/2,Mtar);

p->LineTo(X(kx),Y(ky));
kx=EixoXo(0.0,1000.0,0.0,&Ang,&Mtar);
ky=EixoYo(0.0,Ang,M_PI/2,Mtar);

 p->MoveTo(X(kx),Y(ky));

 kx=EixoXo(0.0,-1000.0,0.0,&Ang,&Mtar);
ky=EixoYo(0,Ang,M_PI/2,Mtar);

p->LineTo(X(kx),Y(ky));
}
void MoveCubo1(TCanvas *Img,float Lado){
float kx=0;
float ky=0;

kx=EixoXMo(Alpha[0],MVetorG[0]);
ky=EixoYMo(-Lado/2,Alpha[0],BetaT,MVetorG[0]);

Img->MoveTo(X(kx),Y(ky));
 kx=EixoXMo(Alpha[1],MVetorG[1]);
ky=EixoYMo(-Lado/2,Alpha[1],BetaT,MVetorG[1]);
Img->Pen->Color=clRed;
 Img->LineTo(X(kx),Y(ky));

 kx=EixoXMo(Alpha[2],MVetorG[2]);
ky=EixoYMo(-Lado/2,Alpha[2],BetaT,MVetorG[2]);

Img->LineTo(X(kx),Y(ky));


 kx=EixoXMo(Alpha[3],MVetorG[3]);
ky=EixoYMo(-Lado/2,Alpha[3],BetaT,MVetorG[3]);

Img->LineTo(X(kx),Y(ky));

 kx=EixoXMo(Alpha[4],MVetorG[4]);
ky=EixoYMo(-Lado/2,Alpha[4],BetaT,MVetorG[4]);

Img->LineTo(X(kx),Y(ky));


 kx=EixoXMo(Alpha[5],MVetorG[5]);
ky=EixoYMo(Lado/2,Alpha[5],BetaT,MVetorG[5]);
Img->Pen->Color=clBlue;
Img->LineTo(X(kx),Y(ky));


}


void CuboLimpa(float Lado){



   float kx;
float ky;
Form2->Canvas->Pen->Color=clWhite;
kx=EixoXMX(-Lado/2,Alpha[0],Beta[0],Teta,MVetorG[0]);
ky=EixoYMY2(-Lado/2,0,Alpha[0],Beta[0],Teta,MVetorG[0]);

Form2->Canvas->MoveTo(X(kx),Y(ky));
 kx=EixoXMX(-Lado/2,Alpha[1],Beta[1],Teta,MVetorG[1]);
ky=EixoYMY2(-Lado/2,0,Alpha[1],Beta[1],Teta,MVetorG[1]);

Form2->Canvas->LineTo(X(kx),Y(ky));

 kx=EixoXMX(Lado/2,Alpha[2],Beta[2],Teta,MVetorG[2]);
ky=EixoYMY2(Lado/2,0,Alpha[2],Beta[2],Teta,MVetorG[2]);
 Form2->Canvas->LineTo(X(kx),Y(ky));
  kx=EixoXMX(Lado/2,Alpha[3],Beta[3],Teta,MVetorG[3]);
ky=EixoYMY2(Lado/2,0,Alpha[3],Beta[3],Teta,MVetorG[3]);
Form2->Canvas->LineTo(X(kx),Y(ky));
 kx=EixoXMX(-Lado/2,Alpha[4],Beta[4],Teta,MVetorG[4]);
ky=EixoYMY2(-Lado/2,0,Alpha[4],Beta[4],Teta,MVetorG[4]);
 Form2->Canvas->LineTo(X(kx),Y(ky));




}

void __fastcall TForm2::Button3Click(TObject *Sender)
{
int i;
Form2->Canvas->Pen->Color= clWhite;
Form2->Canvas->MoveTo(X(EixoXM(Alpha[0],Beta[0],Teta,MVetorG[0])),Y(EixoYM(Alpha[0],Beta[0],Teta,MVetorG[0])));
Form2->Canvas->LineTo(X(EixoXM(Alpha[1],Beta[1],Teta,MVetorG[1])),Y(EixoYM(Alpha[1],Beta[1],Teta,MVetorG[1])));


Form2->Canvas->LineTo(X(EixoXM(Alpha[2],Beta[2],Teta,MVetorG[2])),Y(EixoYM(Alpha[2],Beta[2],Teta,MVetorG[2])));

Form2->Canvas->LineTo(X(EixoXM(Alpha[3],Beta[3],Teta,MVetorG[3])),Y(EixoYM(Alpha[3],Beta[3],Teta,MVetorG[3])));

Form2->Canvas->LineTo(X(EixoXM(Alpha[0],Beta[0],Teta,MVetorG[0])),Y(EixoYM(Alpha[0],Beta[0],Teta,MVetorG[0])));
 Form2->Canvas->LineTo(X(EixoXM(Alpha[0],Beta[0],Teta,MVetorG[0])),Y(EixoYM(Alpha[0],Beta[0],Teta,MVetorG[0])));

for (i = 0; i < 4; i++) {
   Alpha[i]=Alpha[i]+M_PI/50;
}
Form2->Canvas->Pen->Color= clRed;
Form2->Canvas->MoveTo(X(EixoXM(Alpha[0],Beta[0],Teta,MVetorG[0])),Y(EixoYM(Alpha[0],Beta[0],Teta,MVetorG[0])));
Form2->Canvas->LineTo(X(EixoXM(Alpha[1],Beta[1],Teta,MVetorG[1])),Y(EixoYM(Alpha[1],Beta[1],Teta,MVetorG[1])));
 Form2->Canvas->Pen->Color= clBlue;

Form2->Canvas->LineTo(X(EixoXM(Alpha[2],Beta[2],Teta,MVetorG[2])),Y(EixoYM(Alpha[2],Beta[2],Teta,MVetorG[2])));
Form2->Canvas->Pen->Color= clLime;
Form2->Canvas->LineTo(X(EixoXM(Alpha[3],Beta[3],Teta,MVetorG[3])),Y(EixoYM(Alpha[3],Beta[3],Teta,MVetorG[3])));
Form2->Canvas->Pen->Color= clYellow;

Form2->Canvas->LineTo(X(EixoXM(Alpha[0],Beta[0],Teta,MVetorG[0])),Y(EixoYM(Alpha[0],Beta[0],Teta,MVetorG[0])));





}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button4Click(TObject *Sender)
{
int i;
Form2->Canvas->Pen->Color= clWhite;
Form2->Canvas->MoveTo(X(EixoXM(Alpha[0],Beta[0],Teta,MVetorG[0])),Y(EixoYM(Alpha[0],Beta[0],Teta,MVetorG[0])));
Form2->Canvas->LineTo(X(EixoXM(Alpha[1],Beta[1],Teta,MVetorG[1])),Y(EixoYM(Alpha[1],Beta[1],Teta,MVetorG[1])));


Form2->Canvas->LineTo(X(EixoXM(Alpha[2],Beta[2],Teta,MVetorG[2])),Y(EixoYM(Alpha[2],Beta[2],Teta,MVetorG[2])));

Form2->Canvas->LineTo(X(EixoXM(Alpha[3],Beta[3],Teta,MVetorG[3])),Y(EixoYM(Alpha[3],Beta[3],Teta,MVetorG[3])));

Form2->Canvas->LineTo(X(EixoXM(Alpha[0],Beta[0],Teta,MVetorG[0])),Y(EixoYM(Alpha[0],Beta[0],Teta,MVetorG[0])));



for (i = 0; i < 4; i++) {
   Beta[i]=Beta[i]+M_PI/50;
}
Form2->Canvas->Pen->Color= clRed;
Form2->Canvas->MoveTo(X(EixoXM(Alpha[0],Beta[0],Teta,MVetorG[0])),Y(EixoYM(Alpha[0],Beta[0],Teta,MVetorG[0])));
Form2->Canvas->LineTo(X(EixoXM(Alpha[1],Beta[1],Teta,MVetorG[1])),Y(EixoYM(Alpha[1],Beta[1],Teta,MVetorG[1])));
 Form2->Canvas->Pen->Color= clBlue;

Form2->Canvas->LineTo(X(EixoXM(Alpha[2],Beta[2],Teta,MVetorG[2])),Y(EixoYM(Alpha[2],Beta[2],Teta,MVetorG[2])));
Form2->Canvas->Pen->Color= clLime;
Form2->Canvas->LineTo(X(EixoXM(Alpha[3],Beta[3],Teta,MVetorG[3])),Y(EixoYM(Alpha[3],Beta[3],Teta,MVetorG[3])));
Form2->Canvas->Pen->Color= clYellow;
Form2->Canvas->LineTo(X(EixoXM(Alpha[0],Beta[0],Teta,MVetorG[0])),Y(EixoYM(Alpha[0],Beta[0],Teta,MVetorG[0])));


}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button5Click(TObject *Sender)

{
 int i;
 for (i = 0; i < 4; i++) {
	Alpha[i]=Alpha[i]+M_PI/50;
 }
 P[0].x=  X(EixoXM(Alpha[0],Beta[0],Teta,MVetorG[0]));
 P[0].y= Y(EixoYM(Alpha[0],Beta[0],Teta,MVetorG[0]));
 P[1].x= X(EixoXM(Alpha[1],Beta[1],Teta,MVetorG[1]));
 P[1].y=  Y(EixoYM(Alpha[1],Beta[1],Teta,MVetorG[1]));
 P[2].x=   X(EixoXM(Alpha[2],Beta[2],Teta,MVetorG[2]));
 P[2].y=  Y(EixoYM(Alpha[2],Beta[2],Teta,MVetorG[2]));
 P[3].x= X(EixoXM(Alpha[3],Beta[3],Teta,MVetorG[3])) ;
 P[3].y=  Y(EixoYM(Alpha[3],Beta[3],Teta,MVetorG[3]));

 Form2->Canvas->Polyline(P,3);


}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button7Click(TObject *Sender)
{

 float kx;
 float ky;

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button8Click(TObject *Sender)
{
 Form2->Canvas->Pen->Color= clWhite;
Form2->Canvas->MoveTo(X(EixoXMX(-1,Alpha[0],Beta[0],Teta,MVetorG[0])),Y(EixoYMY(-1,Alpha[0],Beta[0],Teta,MVetorG[0]))) ;
Form2->Canvas->LineTo(X(EixoXMX(0,Alpha[1],Beta[1],Teta,MVetorG[1])),Y(EixoYMY(0,Alpha[1],Beta[1],Teta,MVetorG[1]))) ;
int i;
for (i = 0; i < 2; i++) {
   Alpha[i]=Alpha[i]+M_PI/50;
}
Form2->Canvas->Pen->Color= clBlue;
Form2->Canvas->MoveTo(X(EixoXMX(-1,Alpha[0],Beta[0],Teta,MVetorG[0])),Y(EixoYMY(-1,Alpha[0],Beta[0],Teta,MVetorG[0]))) ;
Form2->Canvas->LineTo(X(EixoXMX(0,Alpha[1],Beta[1],Teta,MVetorG[1])),Y(EixoYMY(0,Alpha[1],Beta[1],Teta,MVetorG[1]))) ;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button9Click(TObject *Sender)
{
 Form2->Canvas->Pen->Color= clWhite;
Form2->Canvas->MoveTo(X(EixoXMX(-1,Alpha[0],Beta[0],Teta,MVetorG[0])),Y(EixoYMY(-1,Alpha[0],Beta[0],Teta,MVetorG[0]))) ;
Form2->Canvas->LineTo(X(EixoXMX(0,Alpha[1],Beta[1],Teta,MVetorG[1])),Y(EixoYMY(0,Alpha[1],Beta[1],Teta,MVetorG[1]))) ;
int i;
for (i = 0; i < 2; i++) {
   Beta[i]=Beta[i]+M_PI/50;
}

Form2->Canvas->Pen->Color= clBlue;
Form2->Canvas->MoveTo(X(EixoXMX(-1,Alpha[0],Beta[0],Teta,MVetorG[0])),Y(EixoYMY(-1,Alpha[0],Beta[0],Teta,MVetorG[0]))) ;
Form2->Canvas->LineTo(X(EixoXMX(1,Alpha[1],Beta[1],Teta,MVetorG[1])),Y(EixoYMY(1,Alpha[1],Beta[1],Teta,MVetorG[1]))) ;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button10Click(TObject *Sender)
{
 int i;
 float kx;
 float ky;
 Form2->Canvas->Pen->Color= clWhite;
 kx=EixoXMX(0,Alpha[0],Beta[0],Teta,MVetorG[0])-1;
ky=EixoYMY2(0,0,Alpha[0],Beta[0],Teta,MVetorG[0])-1;
Form2->Canvas->MoveTo(X(kx),Y(ky));
kx=EixoXMX(0,Alpha[1],Beta[1],Teta,MVetorG[1]);
ky=EixoYMY2(-1,0,Alpha[1],Beta[1],Teta,MVetorG[1]);

Form2->Canvas->LineTo(X(kx),Y(ky));

 kx=EixoXMX(0,Alpha[2],Beta[2],Teta,MVetorG[2]);
 ky=EixoYMY2(-1,-150,Alpha[2],Beta[2],Teta,MVetorG[2]);

 Form2->Canvas->LineTo(X(kx),Y(ky));

Form2->Canvas->Pen->Color= clBlue;
for (i = 0; i < 3; i++) {
 Beta[i]=Beta[i]+M_PI/50;
}

kx=EixoXMX(0,Alpha[0],Beta[0],Teta,MVetorG[0])-1;
ky=EixoYMY2(0,0,Alpha[0],Beta[0],Teta,MVetorG[0]);
Form2->Canvas->MoveTo(X(kx),Y(ky));
kx=EixoXMX(0,Alpha[1],Beta[1],Teta,MVetorG[1]);
ky=EixoYMY2(-1,0,Alpha[1],Beta[1],Teta,MVetorG[1]);

Form2->Canvas->LineTo(X(kx),Y(ky));
Form2->Canvas->Pen->Color= clLime;
 kx=EixoXMX(0,Alpha[2],Beta[2],Teta,MVetorG[2]);
 ky=EixoYMY2(-1,-150,Alpha[2],Beta[2],Teta,MVetorG[2]);

 Form2->Canvas->LineTo(X(kx),Y(ky));
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button11Click(TObject *Sender)
{
 int i;
 float kx;
 float ky;

Form2->Canvas->Pen->Color= clBlue;
for (i = 0; i < 3; i++) {
 Alpha[i]=Alpha[i]+M_PI/50;
}

kx=EixoXMX(0,Alpha[0],Beta[0],Teta,MVetorG[0])-1;
ky=EixoYMY2(0,0,Alpha[0],Beta[0],Teta,MVetorG[0]);
Form2->Canvas->MoveTo(X(kx),Y(ky));
kx=EixoXMX(0,Alpha[1],Beta[1],Teta,MVetorG[1]);
ky=EixoYMY2(-1,0,Alpha[1],Beta[1],Teta,MVetorG[1]);

Form2->Canvas->LineTo(X(kx),Y(ky));
Form2->Canvas->Pen->Color= clLime;
 kx=EixoXMX(0,Alpha[2],Beta[2],Teta,MVetorG[2]);
 ky=EixoYMY2(-1,-150,Alpha[2],Beta[2],Teta,MVetorG[2]);

 Form2->Canvas->LineTo(X(kx),Y(ky));

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button12Click(TObject *Sender)
{
 float kx;
 float ky;

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button13Click(TObject *Sender)
{
Cubo(250);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button14Click(TObject *Sender)
{
int i;
CuboLimpa(250);
for (i = 0; i < 5; i++) {
  Beta[i]=Beta[i]+M_PI/50;
}
CuboBeta(250);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button15Click(TObject *Sender)
{
int i;

CuboLimpa(250);
for (i = 0; i < 5; i++) {
  Alpha[i]=Alpha[i]+M_PI/50;
}
CuboAlpha(250);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button16Click(TObject *Sender)
{

float kx=0;
float ky=0;


}

//---------------------------------------------------------------------------

void __fastcall TForm2::Button17Click(TObject *Sender)
{
 int i;
   float kx=0;
float ky=0;
float Lado=250;
float MPIA[100];

Limpa2();
 for (i = 0; i < 16; i++) {
  Alpha[i]=Alpha[i]+M_PI/50;

}


Form2->Canvas->Pen->Color=clRed;
kx=EixoXMX(0,Alpha[0],Beta[0],Teta,MVetorG[0]);
ky=EixoYMY3(0,0,Alpha[0],Beta[0],Teta,MVetorG[0]);

Form2->Canvas->MoveTo(X(kx),Y(ky));
 kx=EixoXMX(0,Alpha[1],Beta[1],Teta,MVetorG[1]);
ky=EixoYMY3(-150,0,Alpha[1],Beta[1],Teta,MVetorG[1]);

Form2->Canvas->LineTo(X(kx),Y(ky));
 Form2->Canvas->Pen->Color=clBlue;
 kx=EixoXMX(0,Alpha[2],Beta[2],Teta,MVetorG[2]);
ky=EixoYMY3(-150,0,Alpha[2],Beta[2],Teta,MVetorG[2]);

Form2->Canvas->LineTo(X(kx),Y(ky));
 kx=EixoXMX(0,Alpha[3],Beta[3],Teta,MVetorG[3]);
ky=EixoYMY3(150,0,Alpha[3],Beta[3],Teta,MVetorG[3]);
Form2->Canvas->Pen->Color=clYellow;
Form2->Canvas->LineTo(X(kx),Y(ky));
 kx=EixoXMX(0,Alpha[4],Beta[4],Teta,MVetorG[4]);
ky=EixoYMY3(-150,0,Alpha[4],Beta[4],Teta,MVetorG[4]);
Form2->Canvas->Pen->Color=clLime;
Form2->Canvas->LineTo(X(kx),Y(ky));

  kx=EixoXMX(0,Alpha[5],Beta[5],Teta,MVetorG[5]);
ky=EixoYMY3(-150,300,Alpha[5],Beta[5],Teta,MVetorG[5]);
Form2->Canvas->Pen->Color=clGreen;
Form2->Canvas->LineTo(X(kx),Y(ky));
 kx=EixoXMX(0,Alpha[6],Beta[6],Teta,MVetorG[6]);
ky=EixoYMY3(-150,300,Alpha[6],Beta[6],Teta,MVetorG[6]);
Form2->Canvas->Pen->Color=clGreen;
Form2->Canvas->LineTo(X(kx),Y(ky));
kx=EixoXMX(0,Alpha[7],Beta[7],Teta,MVetorG[7]);
ky=EixoYMY3(-150,0,Alpha[7],Beta[7],Teta,MVetorG[7]);

Form2->Canvas->LineTo(X(kx),Y(ky));
 kx=EixoXMX(0,Alpha[8],Beta[8],Teta,MVetorG[8]);
ky=EixoYMY3(-150,0,Alpha[8],Beta[8],Teta,MVetorG[8]);
Form2->Canvas->Pen->Color=clRed;
Form2->Canvas->MoveTo(X(kx),Y(ky));

  kx=EixoXMX(0,Alpha[9],Beta[9],Teta,MVetorG[9]);
ky=EixoYMY3(-150,300,Alpha[9],Beta[9],Teta,MVetorG[9]);
Form2->Canvas->Pen->Color=clRed;
Form2->Canvas->LineTo(X(kx),Y(ky));
   kx=EixoXMX(0,Alpha[10],Beta[10],Teta,MVetorG[10]);
ky=EixoYMY3(-150,300,Alpha[10],Beta[10],Teta,MVetorG[10]);
Form2->Canvas->Pen->Color=clRed;
Form2->Canvas->LineTo(X(kx),Y(ky));
 kx=EixoXMX(0,Alpha[11],Beta[11],Teta,MVetorG[11]);
ky=EixoYMY3(-150,300,Alpha[11],Beta[11],Teta,MVetorG[11]);
Form2->Canvas->Pen->Color=clRed;
Form2->Canvas->MoveTo(X(kx),Y(ky));
kx=EixoXMX(0,Alpha[12],Beta[12],Teta,MVetorG[12]);
ky=EixoYMY3(-150,300,Alpha[12],Beta[12],Teta,MVetorG[12]);
Form2->Canvas->Pen->Color=clRed;
Form2->Canvas->LineTo(X(kx),Y(ky));
kx=EixoXMX(0,Alpha[13],Beta[13],Teta,MVetorG[13]);
ky=EixoYMY3(-150,0,Alpha[13],Beta[13],Teta,MVetorG[13]);
Form2->Canvas->Pen->Color=clRed;
Form2->Canvas->LineTo(X(kx),Y(ky));
kx=EixoXMX(0,Alpha[14],Beta[14],Teta,MVetorG[14]);
ky=EixoYMY3(-150,300,Alpha[14],Beta[14],Teta,MVetorG[14]);
Form2->Canvas->Pen->Color=clRed;
Form2->Canvas->MoveTo(X(kx),Y(ky));
kx=EixoXMX(0,Alpha[15],Beta[15],Teta,MVetorG[15]);
ky=EixoYMY3(-150,300,Alpha[15],Beta[15],Teta,MVetorG[15]);
Form2->Canvas->Pen->Color=clRed;
Form2->Canvas->LineTo(X(kx),Y(ky));

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button18Click(TObject *Sender)
{
  int i;
   float kx=0;
float ky=0;
float Lado=250;
float MPIA[100];

Limpa2();
 for (i = 0; i < 16; i++) {
  Beta[i]=Beta[i]+M_PI/25;

}


Form2->Canvas->Pen->Color=clRed;
kx=EixoXMX(0,Alpha[0],Beta[0],Teta,MVetorG[0]);
ky=EixoYMY3(0,0,Alpha[0],Beta[0],Teta,MVetorG[0]);

Form2->Canvas->MoveTo(X(kx),Y(ky));
 kx=EixoXMX(0,Alpha[1],Beta[1],Teta,MVetorG[1]);
ky=EixoYMY3(-150,0,Alpha[1],Beta[1],Teta,MVetorG[1]);

Form2->Canvas->LineTo(X(kx),Y(ky));
 Form2->Canvas->Pen->Color=clBlue;
 kx=EixoXMX(0,Alpha[2],Beta[2],Teta,MVetorG[2]);
ky=EixoYMY3(-150,0,Alpha[2],Beta[2],Teta,MVetorG[2]);

Form2->Canvas->LineTo(X(kx),Y(ky));
 kx=EixoXMX(0,Alpha[3],Beta[3],Teta,MVetorG[3]);
ky=EixoYMY3(150,0,Alpha[3],Beta[3],Teta,MVetorG[3]);
Form2->Canvas->Pen->Color=clYellow;
Form2->Canvas->LineTo(X(kx),Y(ky));
 kx=EixoXMX(0,Alpha[4],Beta[4],Teta,MVetorG[4]);
ky=EixoYMY3(-150,0,Alpha[4],Beta[4],Teta,MVetorG[4]);
Form2->Canvas->Pen->Color=clLime;
Form2->Canvas->LineTo(X(kx),Y(ky));

  kx=EixoXMX(0,Alpha[5],Beta[5],Teta,MVetorG[5]);
ky=EixoYMY3(-150,300,Alpha[5],Beta[5],Teta,MVetorG[5]);
Form2->Canvas->Pen->Color=clGreen;
Form2->Canvas->LineTo(X(kx),Y(ky));
 kx=EixoXMX(0,Alpha[6],Beta[6],Teta,MVetorG[6]);
ky=EixoYMY3(-150,300,Alpha[6],Beta[6],Teta,MVetorG[6]);
Form2->Canvas->Pen->Color=clGreen;
Form2->Canvas->LineTo(X(kx),Y(ky));
kx=EixoXMX(0,Alpha[7],Beta[7],Teta,MVetorG[7]);
ky=EixoYMY3(-150,0,Alpha[7],Beta[7],Teta,MVetorG[7]);

Form2->Canvas->LineTo(X(kx),Y(ky));
 kx=EixoXMX(0,Alpha[8],Beta[8],Teta,MVetorG[8]);
ky=EixoYMY3(-150,0,Alpha[8],Beta[8],Teta,MVetorG[8]);
Form2->Canvas->Pen->Color=clRed;
Form2->Canvas->MoveTo(X(kx),Y(ky));

  kx=EixoXMX(0,Alpha[9],Beta[9],Teta,MVetorG[9]);
ky=EixoYMY3(-150,300,Alpha[9],Beta[9],Teta,MVetorG[9]);
Form2->Canvas->Pen->Color=clRed;
Form2->Canvas->LineTo(X(kx),Y(ky));
   kx=EixoXMX(0,Alpha[10],Beta[10],Teta,MVetorG[10]);
ky=EixoYMY3(-150,300,Alpha[10],Beta[10],Teta,MVetorG[10]);
Form2->Canvas->Pen->Color=clRed;
Form2->Canvas->LineTo(X(kx),Y(ky));
 kx=EixoXMX(0,Alpha[11],Beta[11],Teta,MVetorG[11]);
ky=EixoYMY3(-150,300,Alpha[11],Beta[11],Teta,MVetorG[11]);
Form2->Canvas->Pen->Color=clRed;
Form2->Canvas->MoveTo(X(kx),Y(ky));
kx=EixoXMX(0,Alpha[12],Beta[12],Teta,MVetorG[12]);
ky=EixoYMY3(-150,300,Alpha[12],Beta[12],Teta,MVetorG[12]);
Form2->Canvas->Pen->Color=clRed;
Form2->Canvas->LineTo(X(kx),Y(ky));
kx=EixoXMX(0,Alpha[13],Beta[13],Teta,MVetorG[13]);
ky=EixoYMY3(-150,0,Alpha[13],Beta[13],Teta,MVetorG[13]);
Form2->Canvas->Pen->Color=clRed;
Form2->Canvas->LineTo(X(kx),Y(ky));
kx=EixoXMX(0,Alpha[14],Beta[14],Teta,MVetorG[14]);
ky=EixoYMY3(-150,300,Alpha[14],Beta[14],Teta,MVetorG[14]);
Form2->Canvas->Pen->Color=clRed;
Form2->Canvas->MoveTo(X(kx),Y(ky));
kx=EixoXMX(0,Alpha[15],Beta[15],Teta,MVetorG[15]);
ky=EixoYMY3(-150,300,Alpha[15],Beta[15],Teta,MVetorG[15]);
Form2->Canvas->Pen->Color=clRed;
Form2->Canvas->LineTo(X(kx),Y(ky));
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button19Click(TObject *Sender)
{




Cubo1(Form2->Canvas,300);
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button20Click(TObject *Sender)
{
int i=0;
LimpaCubo1(Image1->Canvas,300);
for (i = 0; i < 10; i++) {
  Alpha[i]=Alpha[i]+M_PI/50;
}

 MoveCubo1(Image1->Canvas,300);

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button21Click(TObject *Sender)
{
LimpaCubo1(Image1->Canvas,300);
int i=0;
BetaT=BetaT+M_PI/50;
MoveCubo1(Image1->Canvas,300);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{

long double Ang;
long double Mtar;


if (Edit1->Text.IsEmpty() ) {
	 Edit1->Text="0";}
if (Edit2->Text.IsEmpty()) {
	 Edit2->Text="0";
}
 if (RadioXoY->Checked) {
	 RXoY->Checked;

 }

 if (RadioZoX->Checked) {
    RZoX->Checked;

 }


Contar=Contar+1;
if ((RadioButton1->Checked)&&(Contar==1)&&(RadioXoY->Checked)) {
  MZo[Contador]=Edit1->Text.ToInt();
  Label1->Caption=FloatToStr(OX(X))+";;;"+FloatToStr(OY(Y));
  kx1=EixoXo(OX(X),OY(Y),MZo[Contador],&Ang,&Mtar);
  ky1=EixoYo(MZo[Contador],Ang,BetaT,Mtar);



   Mkx[Contador]=::X( kx1);
   MAlpha[Contador]=Ang;
   MMVetorG[Contador]=Mtar;
  Mky[Contador]= ::Y(ky1);

	::Move=true;
  }

if ((RadioButton1->Checked)&&(Contar==2)&&(RadioXoY->Checked)) {

  ::Move=false;
  Contar=0;
   LZo[Contador]=Edit1->Text.ToInt();

  Lkx[Contador]=::X(EixoXo(OX(X),OY(Y),0,&Ang,&Mtar));
  Lky[Contador]=::Y(EixoYo(0,Ang,BetaT,Mtar));
  LAlpha[Contador]=Ang;
  LMVetorG[Contador]=Mtar;





  Contador=Contador+1;
  Desenho3DS.SetPosi(Contador);
  }

  if ((RadioButton1->Checked)&&(Contar==1)&&(RadioZoX->Checked)) {

   MZo[Contador]=OY(Y);
   MYo[Contador]=Edit2->Text.ToInt();
  Label1->Caption=FloatToStr(OX(X))+";;;"+FloatToStr(OY(Y));
  kx1=EixoXo(OX(X),MYo[Contador],0,&Ang,&Mtar);
  ky1=EixoYo(OY(Y),Ang,BetaT,Mtar);




   Mkx[Contador]=::X( kx1);
   MAlpha[Contador]=Ang;
   MMVetorG[Contador]=Mtar;
  Mky[Contador]= ::Y(ky1);

	::Move=true;
  }

   if ((RadioButton1->Checked)&&(Contar==2)&&(RadioZoX->Checked)) {
  ::Move=false;
  Contar=0;
   LZo[Contador]=OY(Y);
   LYo[Contador]=Edit2->Text.ToInt();
  Lkx[Contador]=::X(EixoXo(OX(X),LYo[Contador],0,&Ang,&Mtar));
  Lky[Contador]=::Y(EixoYo(OY(Y),Ang,BetaT,Mtar));
  LAlpha[Contador]=Ang;
  LMVetorG[Contador]=Mtar;

  
  Contador=Contador+1;
  Desenho3DS.SetPosi(Contador);

   }


  if (RadioButton2->Checked) {
	 Contar=0;
  }
  if (Contar>4) {
	 Contar=0;
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button22Click(TObject *Sender)
{
float kx=0;
float ky=0;
float Mtar[10];
float Lado;
long double Ang[10];
Eixos(Image1->Canvas);

}
//---------------------------------------------------------------------------


void __fastcall TForm2::Image1MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
   bool g=false;
  int kx[5000];
int ky[5000];
int LLLkx;
int LLLky;
int MLLkx;
int MLLky;
TRect P;
TPoint MP[2];
long double Ang;
long double Mtar;
Image1->Canvas->Brush->Color=clWhite;

	if ((RadioButton1->Checked)&&(::Move)&&(RadioXoY->Checked)) {
	 Image1->Canvas->MoveTo(::X(kx1),::Y(ky1));

kx[1]=EixoXo(OX(X),OY(Y),Zo[Contador],&Ang,&Mtar);
 ky[1]=EixoYo(Zo[Contador],Ang,M_PI/2,Mtar);
	  if (g){


     if ((::X(kx[1])>=::X(kx1))&&(::Y(ky[1])>=::Y(ky1))) {
	P=TRect( ::X(kx1)-30,::Y(ky1)-30,X+30,Y+30);
  }
	if ((::X(kx[1])>(::X(kx1)))&&(::Y(ky[1])<(::Y(ky1)))) {
	P=TRect( ::X(kx1)-30,::Y(ky1)+30, X+30,Y-30);

  }
		if ((::X(kx[1])<(::X(kx1)))&&(::Y(ky[1])>(::Y(ky1)))){

			P=TRect( ::X(kx1)+30,::Y(ky1)-50, X-30,Y+30);

		}
			if ((::X(kx[1])<(::X(kx1)))&&(::Y(ky[1])<(::Y(ky1)))){

			P=TRect( ::X(kx1)+30,::Y(ky1)+30, X-30,Y-30);

		}


	   }
	   Image1->Canvas->FillRect(P);
  Image1->Canvas->Pen->Color=clRed;


  Label1->Caption=FloatToStr(kx[1])+";"+FloatToStr(ky[1]);


   MLLkx= ::X(kx1);
   MLLky= ::Y(ky1) ;
   LLLkx= ::X(kx[1]);
   LLLky=::Y(ky[1]);
   MP[0].x=MLLkx;
   MP[0].y=MLLky;
   MP[1].x=LLLkx;
   MP[1].y= LLLky;
   Image1->Canvas->Pen->Color=clWhite;
   Image1->Canvas->Pen->Width=80;
	 Image1->Canvas->Polyline(MP,1);
	 Image1->Canvas->Pen->Color=clRed;
	 Image1->Canvas->Pen->Width=0;


		Image1->Canvas->Polyline(MP,1);





  }

	if ((RadioButton1->Checked)&&(::Move)&&(RadioZoX->Checked)) {

	  kx[1]=EixoXo(OX(X),0,Zo[Contador],&Ang,&Mtar);
 ky[1]=EixoYo(OY(Y),Ang,0,Mtar);

      MLLkx= ::X(kx1);
   MLLky= ::Y(ky1) ;
   LLLkx= ::X(kx[1]);
   LLLky=::Y(ky[1]);



     MP[0].x=MLLkx;
   MP[0].y=MLLky;
   MP[1].x=LLLkx;
   MP[1].y= LLLky;
   Image1->Canvas->Pen->Color=clWhite;
   Image1->Canvas->Pen->Width=80;
	 Image1->Canvas->Polyline(MP,1);
	 Image1->Canvas->Pen->Color=clRed;
	 Image1->Canvas->Pen->Width=0;


		Image1->Canvas->Polyline(MP,1);

	}

  Label5->Top=Y+50;
  Label5->Left=X+50;
  Label5->Caption="{ "+IntToStr(::OX(X))+ ";"+IntToStr(::Y(Y))+" };";
  kx[0]=X;
  ky[0]=Y;
   Label1->Caption=FloatToStr(::OX(kx[0]))+";"+FloatToStr(::OY(ky[0]));
}
//---------------------------------------------------------------------------
  void MLimpaB(TCanvas *h){
int i=0;
int kx=0;
int ky=0;
Form2->Image1->Canvas->Pen->Color=clWhite;

Form2->Image1->Canvas->Pen->Width=2;
 for (i = 0; i < Contador; i++) {


  Form2->Image1->Canvas->MoveTo(Mkx[i],Mky[i]);

  Form2->Image1->Canvas->LineTo(Lkx[i],Lky[i]);

  }

for (i = 0; i < Contador; i++) {


Form2->Image1->Canvas->MoveTo(LBMkx[i],LBMky[i]);
Form2->Image1->Canvas->LineTo(LBLkx[i],LBLky[i]);
 }
 Form2->Image1->Canvas->Pen->Width=1;
}
void __fastcall TForm2::Button23Click(TObject *Sender)
{
Redesenha(Form2->Image1->Canvas);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Timer1Timer(TObject *Sender)
{
  if (RadioButton1->Checked) {
  Eixos(Image1->Canvas);
}



  Canvas1=Image1->Canvas;
 if (((RXoY->Checked)||(RZoX->Checked)||(BetaTMPI2->Checked)||(BetaT0->Checked)||(RadioButton3->Checked))&&(Contador>0)) {


 if (RXoY->Checked) {

 }
 if (RZoX->Checked) {

 }
 if (CheckBox2->Checked){
  MLimpaB(Image1->Canvas);
  Eixos(Image1->Canvas);

 Redesenha(Image1->Canvas);
 RedesenhaZoX(Image1->Canvas);


 }


}





}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button24Click(TObject *Sender)
{
int i=0;
int kx=0;
int ky;
g=false;
p[0]=clGreen;
p[1]=clBlue;
p[2]=clYellow;
p[3]=clRed;
MLimpaB(Image1->Canvas);

for (i = 0; i < Contador; i++) {
 MAlpha[i]=MAlpha[i]+M_PI/50 ;
 LAlpha[i]=LAlpha[i]+M_PI/50;
}
for (i = 0; i < Contador; i++) {
   kx=EixoXMo(MAlpha[i],MMVetorG[i]);
  ky=EixoYMo(MZo[i],MAlpha[i],BetaT,MMVetorG[i]);
   LBMkx[i]= X(kx);
   LBMky[i]=  Y(ky);
  Image1->Canvas->MoveTo(LBMkx[i],LBMky[i]);
  kx=EixoXMo(LAlpha[i],LMVetorG[i]);
  ky=EixoYMo(LZo[i],LAlpha[i],BetaT,LMVetorG[i]);
  LBLkx[i]= X(kx);
  LBLky[i]= Y(ky);
  Image1->Canvas->Pen->Color=p[i];
  Image1->Canvas->LineTo(LBLkx[i],LBLky[i]);
}


}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button25Click(TObject *Sender)
{
int i=0;
int kx=0;
int ky=0;
TPoint MP[2];
g=false;
p[0]=clGreen;
p[1]=clBlue;
p[2]=clYellow;
p[3]=clRed;


 MLimpaB(Image1->Canvas);
 Image1->Canvas->Pen->Width=0;
for (i = 4; i < 100; i++) {
  p[i]=clBlack;
}
BetaT=BetaT+M_PI/50;




  for (i = 0; i < Contador; i++) {
  kx=EixoXMo(MAlpha[i],MMVetorG[i]);
  ky=EixoYMo(MZo[i],MAlpha[i],BetaT,MMVetorG[i]);
  LBMkx[i]=X(kx);
  LBMky[i]=Y(ky);
  MP[0].x= LBMkx[i];
  MP[0].y= LBMky[i];

  kx=EixoXMo(LAlpha[i],LMVetorG[i]);
  ky=EixoYMo(LZo[i],LAlpha[i],BetaT,LMVetorG[i]);

  LBLkx[i]= X(kx);
  LBLky[i]=Y(ky);
  MP[1].x=LBLkx[i];
  MP[1].y=  LBLky[i];

  Form2->Image1->Canvas->Pen->Color=p[i];
   Form2->Image1->Canvas->Polyline(MP,1);

}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Edit1DblClick(TObject *Sender)
{
Edit1->Clear();
}
//---------------------------------------------------------------------------




void __fastcall TForm2::Button26Click(TObject *Sender)
{
Canvas1=Image1->Canvas;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button27Click(TObject *Sender)
{
MLimpa1(Form2->Image1->Canvas);
}
//---------------------------------------------------------------------------



void __fastcall TForm2::Button28Click(TObject *Sender)
{
MLimpaB(Image1->Canvas);
}
//---------------------------------------------------------------------------


void __fastcall TForm2::RadioZoXClick(TObject *Sender)
{
BetaT=0;
BetaT0->Checked=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::RadioXoYClick(TObject *Sender)
{
BetaT=M_PI/2;
BetaTMPI2->Checked=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::BetaT0Click(TObject *Sender)
{
BetaT=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::BetaTMPI2Click(TObject *Sender)
{
BetaT=M_PI/2;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ButtonSalvarClick(TObject *Sender)
{
int k;
int i;
int Cont=0;
GravaArquivo();
UnicodeString FileNome;
char FileUni[500];
if (SaveDialog1->Execute()){
ShowMessage(SaveDialog1->FileName );
FileNome=SaveDialog1->FileName;
}
Cont= FileNome.Length();
for(i=0;i<FileNome.Length();i++){
FileUni[i]=FileNome[i+1];

}
 FileUni[ FileNome.Length()]='\0';


ofstream FDesenho(FileUni,ios::binary);


if (!FDesenho) {
  ShowMessage("Arquivo N�o pode ser Aberto...");



}



  FDesenho.seekp(0*sizeof(Desenho3DS));

  ShowMessage(IntToStr(Desenho3DS.GetPosi()));
  for (i = 0; i < Contador; i++) {


 FDesenho.write(reinterpret_cast<const char *>(&Desenho3DS),sizeof(Desenho3DS));

  }

}
//---------------------------------------------------------------------------

void __fastcall TForm2::ButtonRecuperaClick(TObject *Sender)
{
int Posi;

int i=0;
int kx=0;
int ky=0;
TPoint MP[2];
g=false;
p[0]=clGreen;
p[1]=clBlue;
p[2]=clYellow;
p[3]=clRed;
float AlphaBlend[1000];

 UnicodeString FileNome;
char FileUni[500];
if (OpenDialog1->Execute()){

FileNome=OpenDialog1->FileName;
}
int Cont= FileNome.Length();
for(i=0;i<FileNome.Length();i++){
FileUni[i]=FileNome[i+1];

}
FileUni[Cont]='\0';
ShowMessage(FileUni);







ifstream Recupera(FileUni,ios::in);
if (!Recupera) {
	ShowMessage("Arquivo N�o Pode Ser Lido...");
}
while (Recupera &&!Recupera.eof()){

Recupera.read(reinterpret_cast<char *>(&Desenho3DS),sizeof(Desenho3DS));
}

ShowMessage(IntToStr(Desenho3DS.GetPosi()));
 Form2->Image1->Canvas->Pen->Width=1;
for (i = 4; i < 100; i++) {
  p[i]=clBlack;
}


   Contador=Desenho3DS.GetPosi();
   BetaT=Desenho3DS.GetBetaT();


   for (i = 0; i < Desenho3DS.GetPosi(); i++) {
  kx=EixoXMo(Desenho3DS.GetMAlpha(i),Desenho3DS.GetMMVetorGr(i));
  ky=EixoYMo(Desenho3DS.GetMzo(i),Desenho3DS.GetMAlpha(i),Desenho3DS.GetBetaT(),Desenho3DS.GetMMVetorGr(i));
  MAlpha[i]=Desenho3DS.GetMAlpha(i);
  MMVetorG[i]=Desenho3DS.GetMMVetorGr(i);
  MZo[i]= Desenho3DS.GetMzo(i);
  LBMkx[i]=X(kx);
  LBMky[i]=Y(ky);
  MP[0].x= LBMkx[i];
  MP[0].y= LBMky[i];



  kx=EixoXMo(Desenho3DS.GetLAlpha(i),Desenho3DS.GetLMVetorGr(i));
  ky=EixoYMo(Desenho3DS.GetLzo(i),Desenho3DS.GetLAlpha(i),Desenho3DS.GetBetaT(),Desenho3DS.GetLMVetorGr(i));
	LAlpha[i]= Desenho3DS.GetLAlpha(i);
	LMVetorG[i]= Desenho3DS.GetLMVetorGr(i);
	LZo[i]=Desenho3DS.GetLzo(i);
  LBLkx[i]= X(kx);
  LBLky[i]=Y(ky);
  MP[1].x=LBLkx[i];
  MP[1].y=  LBLky[i];

  Form2->Image1->Canvas->Pen->Color=p[i];
   Form2->Image1->Canvas->Polyline(MP,1);



  if (i==4) {
    ShowMessage(FloatToStr(Desenho3DS.GetLAlpha(0)));
  }


   }


}
//---------------------------------------------------------------------------

void __fastcall TForm2::ButtonAlphaClick(TObject *Sender)
{
int i=0;
int kx=0;
int ky;
g=false;
p[0]=clGreen;
p[1]=clBlue;
p[2]=clYellow;
p[3]=clRed;
LimpaDesenho3DS(Image1->Canvas);
Image1->Canvas->Pen->Width=0;
for (i = 0; i < Desenho3DS.GetPosi(); i++) {
 Desenho3DS.SetMAlpha(Desenho3DS.GetMAlpha(i)+M_PI/50,i);
 Desenho3DS.SetLAlpha(Desenho3DS.GetLAlpha(i) +M_PI/50,i);
}
for (i = 0; i < Desenho3DS.GetPosi(); i++) {
   kx=EixoXMo(Desenho3DS.GetMAlpha(i) ,Desenho3DS.GetMMVetorGr(i));
  ky=EixoYMo(Desenho3DS.GetMzo(i),Desenho3DS.GetMAlpha(i),Desenho3DS.GetBetaT(),Desenho3DS.GetMMVetorGr(i));
   LBMkx[i]= X(kx);
   LBMky[i]=  Y(ky);
  Image1->Canvas->MoveTo(LBMkx[i],LBMky[i]);
  kx=EixoXMo(Desenho3DS.GetLAlpha(i),Desenho3DS.GetLMVetorGr(i));
  ky=EixoYMo(Desenho3DS.GetLzo(i),Desenho3DS.GetLAlpha(i),Desenho3DS.GetBetaT(),Desenho3DS.GetLMVetorGr(i));
  LBLkx[i]= X(kx);
  LBLky[i]= Y(ky);
  Image1->Canvas->Pen->Color=p[i];
  Image1->Canvas->LineTo(LBLkx[i],LBLky[i]);
}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ButtonBetaClick(TObject *Sender)
{

  int i=0;
int kx=0;
int ky=0;
TPoint MP[2];
g=false;
p[0]=clGreen;
p[1]=clBlue;
p[2]=clYellow;
p[3]=clRed;

 LimpaDesenho3DS(Image1->Canvas);

 Image1->Canvas->Pen->Width=0;
for (i = 4; i < 100; i++) {
  p[i]=clBlack;
}
Desenho3DS.SetBetaT(Desenho3DS.GetBetaT()+M_PI/50);




  for (i = 0; i < Desenho3DS.GetPosi(); i++) {
  kx=EixoXMo(Desenho3DS.GetMAlpha(i),Desenho3DS.GetMMVetorGr(i));
  ky=EixoYMo(Desenho3DS.GetMzo(i),Desenho3DS.GetMAlpha(i),Desenho3DS.GetBetaT(),Desenho3DS.GetMMVetorGr(i));
  LBMkx[i]=X(kx);
  LBMky[i]=Y(ky);
  MP[0].x= LBMkx[i];
  MP[0].y= LBMky[i];

  kx=EixoXMo(Desenho3DS.GetLAlpha(i),Desenho3DS.GetLMVetorGr(i));
  ky=EixoYMo(Desenho3DS.GetLzo(i),Desenho3DS.GetLAlpha(i),Desenho3DS.GetBetaT(),Desenho3DS.GetLMVetorGr(i));

  LBLkx[i]= X(kx);
  LBLky[i]=Y(ky);
  MP[1].x=LBLkx[i];
  MP[1].y=  LBLky[i];

  Form2->Image1->Canvas->Pen->Color=p[i];
   Form2->Image1->Canvas->Polyline(MP,1);

}

}
//---------------------------------------------------------------------------
void LimpaDesenho3DS(TCanvas *Canvas3DS){



  int i=0;
float kx=0.0;
float ky=0.0;
TPoint MP[2];
g=false;



 Canvas3DS->Pen->Width=2;
Canvas3DS->Pen->Color=clWhite;





  for (i = 0; i < Desenho3DS.GetPosi(); i++) {
  kx=EixoXMo(Desenho3DS.GetMAlpha(i),Desenho3DS.GetMMVetorGr(i));
  ky=EixoYMo(Desenho3DS.GetMzo(i),Desenho3DS.GetMAlpha(i),Desenho3DS.GetBetaT(),Desenho3DS.GetMMVetorGr(i));
  LBMkx[i]=OX(floor(kx));
  LBMky[i]=OY(floor(ky));
  MP[0].x= LBMkx[i];
  MP[0].y= LBMky[i];

  kx=EixoXMo(Desenho3DS.GetLAlpha(i),Desenho3DS.GetLMVetorGr(i));
  ky=EixoYMo(Desenho3DS.GetLzo(i),Desenho3DS.GetLAlpha(i),Desenho3DS.GetBetaT(),Desenho3DS.GetLMVetorGr(i));

  LBLkx[i]= OX(floor(kx));
  LBLky[i]=OY(floor(ky));
  MP[1].x=LBLkx[i];
  MP[1].y=  LBLky[i];


   Canvas3DS->Polyline(MP,1);






}
  }
  void GravaArquivo(){
   int i;
	ShowMessage(IntToStr(Contador));
    Desenho3DS.SetPosi(Contador);

   for (i = 0; i < Contador; i++) {



   Desenho3DS.SetMAlpha(MAlpha[i],i);
   Desenho3DS.SetLAlpha(LAlpha[i],i);
   Desenho3DS.SetMMVetorGr(MMVetorG[i],i);
   Desenho3DS.SetLMVetorGr(LMVetorG[i],i);
   Desenho3DS.SetBetaT(BetaT);
   Desenho3DS.SetMZo(MZo[i],i);
   Desenho3DS.SetLZo(LZo[i],i);
   }





  }
void __fastcall TForm2::ButtonLimpaClick(TObject *Sender)
{

Image1->Canvas->FillRect(ClientRect);

}
//---------------------------------------------------------------------------





void __fastcall TForm2::RadioButton1Click(TObject *Sender)
{     if ( RadioXoY->Checked){
BetaT=M_PI/2;
}
if (  RadioZoX->Checked){
BetaT=0;
BetaT0->Checked=true;
}

      CheckBox2->Checked=true;

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button29Click(TObject *Sender)
{
int i=0;

long double kx=0.0;
long double ky=0.0;
g=false;
p[0]=clGreen;
p[1]=clBlue;
p[2]=clYellow;
p[3]=clRed;
MLimpaB(Image1->Canvas);

for (i = 0; i < Contador; i++) {
MMVetorG[i]=MMVetorG[i]+MMVetorG[i]*0.1;
 LMVetorG[i]=LMVetorG[i]+LMVetorG[i]*0.1;
}
for (i = 0; i < Contador; i++) {
   kx= EixoXMo(MAlpha[i],MMVetorG[i]);
  ky=EixoYMo(MZo[i],MAlpha[i],BetaT,MMVetorG[i]);
   LBMkx[i]= OX(floor(kx));
   LBMky[i]=  OY(floor(ky));
  Image1->Canvas->MoveTo(LBMkx[i],LBMky[i]);
  kx=EixoXMo(LAlpha[i],LMVetorG[i]);
  ky=EixoYMo(LZo[i],LAlpha[i],BetaT,LMVetorG[i]);
  LBLkx[i]= OX(floor(kx));
  LBLky[i]= OY(floor(ky));
  Image1->Canvas->Pen->Color=p[i];
  Image1->Canvas->LineTo(LBLkx[i],LBLky[i]);
}

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button30Click(TObject *Sender)
{
int i=0;
float kx=0.0;
float ky=0.0;
g=false;
p[0]=clGreen;
p[1]=clBlue;
p[2]=clYellow;
p[3]=clRed;
MLimpaB(Image1->Canvas);

for (i = 0; i < Contador; i++) {
MMVetorG[i]=MMVetorG[i]/1.1;
 LMVetorG[i]=LMVetorG[i]/1.1 ;
}
for (i = 0; i < Contador; i++) {
   kx=EixoXMo(MAlpha[i],MMVetorG[i]);
  ky=EixoYMo(MZo[i],MAlpha[i],BetaT,MMVetorG[i]);
   LBMkx[i]= OX(floor(kx));
   LBMky[i]=  OY(floor(ky));
  Image1->Canvas->MoveTo(LBMkx[i],LBMky[i]);
  kx=EixoXMo(LAlpha[i],LMVetorG[i]);
  ky=EixoYMo(LZo[i],LAlpha[i],BetaT,LMVetorG[i]);
  LBLkx[i]= OX(floor(kx));
  LBLky[i]= OY(floor(ky));
  Image1->Canvas->Pen->Color=p[i];
  Image1->Canvas->LineTo(LBLkx[i],LBLky[i]);
}
}
//---------------------------------------------------------------------------
void LimpaZoX(TCanvas *h){

  int i=0;
int kx=0;
int ky=0;
int kx1=0;
int ky1=0;
TPoint MP[2];
g=false;
p[0]=clGreen;
p[1]=clBlue;
p[2]=clYellow;
p[3]=clRed;
float BetaTDes;

 Form2->Image1->Canvas->Pen->Width=3;
 if (Form2->RZoX->Checked){
	  BetaTDes=0;
for (i = 4; i < 100; i++) {
  p[i]=clBlack;
}


   Desenho3DS.SetPosi(Contador);


   for (i = 0; i < Contador; i++) {
  kx1=EixoXMo(MAlpha[i],MMVetorG[i]);
  ky1=EixoYMo(MZo[i],MAlpha[i],BetaTDes,MMVetorG[i]);
  LBMkx[i]=X(kx1);
  LBMky[i]=Y(ky1);
  MP[0].x= LBMkx[i];
  MP[0].y= LBMky[i];

  kx=EixoXMo(LAlpha[i],LMVetorG[i]);
  ky=EixoYMo(LZo[i],LAlpha[i],BetaTDes,LMVetorG[i]);

  LBLkx[i]= X(kx);
  LBLky[i]=Y(ky);
  MP[1].x=LBLkx[i];
  MP[1].y=  LBLky[i];

  Form2->Image1->Canvas->Pen->Color=clWhite;
   Form2->Image1->Canvas->Polyline(MP,1);





   }
 }

  if (Form2->RXoY->Checked){
	  BetaTDes=M_PI/2;
for (i = 4; i < 100; i++) {
  p[i]=clBlack;
}


   Desenho3DS.SetPosi(Contador);


   for (i = 0; i < Contador; i++) {
  kx1=EixoXMo(MAlpha[i],MMVetorG[i]);
  ky1=EixoYMo(MZo[i],MAlpha[i],BetaTDes,MMVetorG[i]);
  LBMkx[i]=X(kx);
  LBMky[i]=Y(ky);
  MP[0].x= LBMkx[i];
  MP[0].y= LBMky[i];

  kx=EixoXMo(LAlpha[i],LMVetorG[i]);
  ky=EixoYMo(LZo[i],LAlpha[i],BetaTDes,LMVetorG[i]);

  LBLkx[i]= X(kx);
  LBLky[i]=Y(ky);
  MP[1].x=LBLkx[i];
  MP[1].y=  LBLky[i];

  Form2->Image1->Canvas->Pen->Color=p[i];
   Form2->Image1->Canvas->Polyline(MP,1);





   }
 }







}

void __fastcall TForm2::Button31Click(TObject *Sender)
{
LimpaRedesenhaDesloca(Image1->Canvas);
KxOO=KxOO-50;

  RedesenhaDesloca(Form2->Image1->Canvas);

}
//---------------------------------------------------------------------------



void __fastcall TForm2::Button33Click(TObject *Sender)
{
  LimpaRedesenhaDesloca(Image1->Canvas);
   KxOO=KxOO+50;

  RedesenhaDesloca(Form2->Image1->Canvas);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button32Click(TObject *Sender)
{
LimpaRedesenhaDesloca(Image1->Canvas);
KyOO=KyOO-50;

  RedesenhaDesloca(Form2->Image1->Canvas);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button34Click(TObject *Sender)
{
LimpaRedesenhaDesloca(Image1->Canvas);
KyOO=KyOO+50;

  RedesenhaDesloca(Form2->Image1->Canvas);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::CloseClick(TObject *Sender)
{
Form2->Close;
}
//---------------------------------------------------------------------------

