#include <stdio.h>
int main()
{
	//Potential Energy Matrix
	int del_x =5, mass=1, omega=1, x=1;
	
	double V[20][20];
	
	for(int i=0;i<del_x;i++)
	{
		for(int j=0;j<del_x;j++)
		{
			if(i == j)
			{
				V[i][j]=0.5*mass*omega*omega*x*x;
				printf("%f", V[i][j]);
			}
			else
			{
				V[i][j]=0;
				printf("%f ", V[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}
