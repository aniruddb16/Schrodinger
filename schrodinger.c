#include <stdio.h>
#include <math.h>
int main()
{
	
	int del_x =5, mass=1, omega=1;
	double x[5]={-1,-0.5,0,0.5,1}; //Position Vector
	double T[20][20]; //Kinetic Energy Matrix
	double V[20][20]; //Potential Energy Matrix
	double H[20][20]; //Hamiltonian Matrix
	const double h = 6;//626070040e-34; //Planck's Constant
	const double P = 3;//141592653589793238; 
	int i;
	int j;
	
	//Potential Energy Operator
	for(i=0;i<del_x;i++)
	{
		for(j=0;j<del_x;j++)
		{
			if(i == j)
			{
				V[i][j]=0.5*mass*omega*omega*x[i]*x[i];
				//printf("%f", V[i][j]);
			}
			else
			{
				V[i][j]=0;
				//printf("%f ", V[i][j]);
			}
		}
		//printf("\n");
	}
	
	
	//Kinetic Energy operator

	for(i=0;i<del_x;i++)
	{
		{
			for(j=0; j<del_x; j++)
			{
				if(i==j)
				{
					T[i][j]= pow(h/del_x , 2)/(24*mass);
					//printf("%f", T[i][j]);
				}
				else
				{
					T[i][j]= pow(h/(2*P*del_x*(i-j)), 2)*pow(-1, i-j);
					//printf("%f", T[i][j]);
				}
			}   
			
		}
	}
	
	
	//ADDING T AND V
	
	for (i=0; i < del_x; i++)
	{
	
        for (j=0; j < del_x; j++) {
            H[i][j] = T[i][j] + V[i][j];
            printf("%f", H[i][j]);
        }
        printf("\n");
    }
	return 0;
}
