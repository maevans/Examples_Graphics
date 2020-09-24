//
//  Ex-LoAt.c
//  
//
//  Created by Mahalia Evans on 9/18/20.
//

//#include "Ex-LoAt.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double f(int,double,double []);
double s,r,b;
FILE *output;
int main()
{
    output=fopen("lorenzdata.dat","w");
    int j,N=3;
    double x[2],dt,y[2],K1[2],K2[2],K3[2],K4[2],ti,t,i;
    printf("\n Introduce parameters s, r and b sepparated by a space:");
    scanf("%lf %lf %lf",&s,&r,&b);
    printf("\n Introduce initial conditions t0,x0,y0 and z0:");
    scanf("%lf %lf %lf %lf",&ti,&x[0],&x[1],&x[2]);
    printf("\n Introduce time step:");
    scanf("%lf",&dt);
    printf("\n Specify time to compute in the equations:");
    scanf("%lf",&t);
/* Loop para Runge Kutta 4 */
    do
    {
      /*  printf("%9.4f %9.4f %9.4f %9.4f \n",ti,x[0],x[1],x[2]); */
        i++;
        for(j=0;j<N;j++)
        {
            K1[j] = f(j,ti,x);
        }
        for(j=0;j<N;j++)
        {
            y[j] = x[j]+(K1[j]/2)*dt;
        }
        for(j=0;j<N;j++)
        {
            K2[j] = f(j,ti+dt/2,y);
        }
        for(j=0;j<N;j++)
        {
            y[j] = x[j]+(K2[j]/2)*dt;
        }
        for(j=0;j<N;j++)
        {
            K3[j] = f(j,ti+dt/2,y);
        }
        for(j=0;j<N;j++)
        {
            y[j] = x[j]+(K3[j])*dt;
        }
        for(j=0;j<N;j++)
        {
            K4[j] = f(j,ti+dt,y);
        }
        for(j=0;j<N;j++)
        {
            x[j] += dt*((K1[j]/6)+(K2[j]/3)+(K3[j]/3)+(K4[j]/6));
        }
        ti +=dt;
        fprintf(output,"%9.4f %9.4f %9.4f \n",x[0],x[1],x[2]);
    }while(i*dt <= t);
    fclose(output);
    return 0;
}
/* Definimos la funcion */
double f(int m,double h,double x[])
{
    if(m==0)
    {
        return s*(x[1]-x[0]);
    }
    else if(m==1)
    {
        return x[0]*(r-x[2])-x[1];
    }
    else if(m==2)
    {
        return x[0]*x[1]-b*x[2];
    }
}
