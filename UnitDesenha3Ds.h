//---------------------------------------------------------------------------

#ifndef UnitDesenha3DsH
#define UnitDesenha3DsH
//---------------------------------------------------------------------------
#include <vcl.h>
#include <math.h>
class VetorDes3Ds{
public:
   VetorDes3Ds(long double);
   int X(int x);
   int Y(int y);
   int OX(float x);
   int OY(float y);
   int OXDes2(int x);
   int OYDes2(int y);
   void Eixos1(TCanvas *);
   long double EixoXo2(long double ,long double  ,  long double *,long double *);
   int EixoYo(long double zo, long double Alphat,long double Betat,long double MVetor);
  float EixoXMo(long double ,long double );
  float EixoYMo(long double ,long double ,long double, long double );
   float GetLAlpha(int );
   float  GetMAlpha(int);
   float GetLMVetorG(int );
   float GetMMVetorG(int);
   float GetBetaT();
  void SetLAlpha(float  ,int );
   void  SetMAlpha(float , int);
   void SetLMVetorG(float ,int );
   void SetBetaT(float);
   void SetMMVetorG(float ,int i);
   int GetPosi1();
   float GetMZo(int);
   void SetMZo(float ,int  );
   float GetLZo(int);
   void SetLZo(float,int);
   void SetPosi1(int);
   void Desenha(TCanvas *);
   void LimpaSesenha(TCanvas*);
   float Beta;

   const Kx;
   const Ky;
   float KOx;
   float KOy;
 float LAlpha[1000];
 float MAlpha[1000];
  float LMVetorG[1000];
   float MMVetor[1000];
	float MZo1[1000];

  float LZo1[1000];

 int Posi1;



};








#endif
