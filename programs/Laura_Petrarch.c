#include <stdio.h>
#include <math.h>
#include <assert.h>

#define SIX (1.0/6.0)

double AP; // vamos a variarla estoasticamente entre (AP-delta , AP+delta)
           // Lo atractivo que es P para L
double AL; // lo atractiva que es L para P
double H, TMAX, aL,bL, GammaL, aP, bP, AL, deltaP, aIP, bIP;
int IMPRESION;

#include "memoria.c"

FILE *fp;

int main(void)
{
  void IC(double y[]);
  void mirk4(double y[],int n, double h, double yout[],
	     double t,void (*derivadas)(double t,
					double y[],double f[]));
  void derivadas(double t, double y[],double f[]);

  double t,*y, *yout, *time;
  int n,flag,J;

  n = 3;

  y=dvector(1,n);
  yout=dvector(1,n);

  IC(y);

  fp=fopen("LP.dat","w");

  J=floor(TMAX/H);  //37
  printf("J=%d\n",J);
  time= dvector(0,J);

  for(j=0;j<=J;j++) time[j]= j*H;

  //fprintf(fp,"%e\t%e\t%e\t%e\n",0.0,y[1],y[2],y[3]);

  for(j=0,flag=1; j <= J ; j++, ++flag){
    mirk4(y,n,H,yout,time[j],derivadas);
    if(flag%IMPRESION == 0){
      fprintf(fp,"%e\t%e\t%e\t%e\n",t,yout[1],yout[2],yout[3]);
      // Incluir AP aleatoria
    }
    if(j%50==0) // funcion aleatoria
    y=yout;
  }

  fclose(fp);

  printf("Datos en LP.dat\n FIN\n");

  return 0;

}

void IC(double y[])
{
  double A1,A2,A3;

  printf("Escriba condiciones iniciales: tres variables del modelo\n");
  scanf("%lf %lf %lf",&A1, &A2, &A3);

  y[1] = A1;
  y[2] = A2;
  y[3] = A3;

  printf("Escriba el tamano del PASO y el tiempo de integracion maximo\n");
  printf("A cada cuantos pasos desea imprimir, escriba un entero\n");
  scanf("%lf %lf %d",&H,&TMAX,&IMPRESION);
  printf("Las condiciones iniciales son y1= %f y2= %f y3= %f\n",
	 y[1],y[2],y[3]);

  printf("El PASO = %f y se integrara de 0 a %f\n",H,TMAX);
  printf("Se imprimira cada %d pasos\n",IMPRESION);

  printf("Escriba aP cercano a 1.0 entre (0.9,1.1)\n");
  scanf("%lf",&aP);
  assert(fabs(aP-1.0) <= 0.1);
  aIP= 0.1*aP;
  aL= 3.0*aP;

  bL= aP;
  bP= 5.0*aP;
  bIP= 10.0*aP;
  GammaL=1.0;
  deltaP=1.0;
  AL= 2.0;
  AP= -1.0;

  printf("aL= %f, bL= %f, GammaL= %f, AP= %f, aP= %f, bP= %f, AL= %f, deltaP= %f, aIP= %f, bIP= %f\n",aL,bL,GammaL,AP,aP,bP,AL,deltaP,aIP,bIP);

}

void derivadas(double t, double y[],double f[])
{
  double L,P,Ip, ap_t;
  double del,w;
  del= 0.1;
  w= 0.05;

  L=y[1];  P= y[2];  Ip= y[3];

  ap_t= AP*(1.0+ del*sin(w*t));
   f[1] = -aL*L + bL*P*(1-(P/GammaL)*(P/GammaL)) + bL*ap_t;
  //  f[1] = -aL*L + bL*P*(1-(P/GammaL)*(P/GammaL)) + bL*AP;
  f[2] = -aP*P + bP*L + bP*AL/(1+deltaP*Ip);
  f[3] = -aIP*Ip + bIP*P;
}


void mirk4(double y[],int n, double h, double yout[],
 double t,void (*derivadas)(double t, double y[],double f[]))
{
  double *k1, *k2, *k3, *k4;
  double *ytemp,*f;
  int j;

  k1=dvector(1,n);
  k2=dvector(1,n);
  k3=dvector(1,n);
  k4=dvector(1,n);
  f=dvector(1,n);

  ytemp=dvector(1,n);

  derivadas(t,y,f);

  for(j=1;j<=n;j++){
    k1[j]=h*f[j];
    ytemp[j]=y[j]+0.5*k1[j];
  }

  derivadas(t+0.5*h,ytemp,f);
  for(j=1;j<=n;j++){
    k2[j]=h*f[j];
    ytemp[j]=y[j]+0.5*k2[j];
  }

  derivadas(t+0.5*h, ytemp,f);
  for(j=1;j<=n;j++){
    k3[j]=h*f[j];
    ytemp[j]=y[j]+k3[j];
  }

  derivadas(t+h, ytemp,f);
  for(j=1;j<=n;j++)
    k4[j]=h*f[j];

  for(j=1;j<=n;j++)
    yout[j]=y[j]+ SIX*(k1[j]+2.0*k2[j]+2.0*k3[j]+k4[j]);

  free_dvector(k1,1,n);
  free_dvector(k2,1,n);
  free_dvector(k3,1,n);
  free_dvector(k4,1,n);
  free_dvector(ytemp,1,n);
  free_dvector(f,1,n);

}
