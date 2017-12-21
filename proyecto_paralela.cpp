#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>

using namespace std;

//void calcular_Distancias(string equipos[][4], float distancias[][], int num)
//{
//	float dist,resta1,resta2;
//	for(int i=0;i<num;i++)
//	{
//		for (int j=0; j<num;j++)
//		{
//			if(i!=j)
//			{
//				resta1=strtof((equipos[i][2]).c_str(),0)-strtof((equipos[j][2]).c_str(),0);
//				resta2=strtof((equipos[i][3]).c_str(),0)-strtof((equipos[j][3]).c_str(),0);
//				dist= sqrt((pow(resta1,2))+(pow(resta2,2)));
//				distancias[i][j]=dist;
//			}
//			else
//			{
//				distancias[i][j]=0;
//			}
//		}
//		j=0;
//	}
//}	

int cantidad_Equipos(char* equipos)
{
	string linea;
	ifstream equi;
	int cont=-1;
	equi.open("hola.csv");

	while(!equi.eof())
	{
		getline(equi,linea);
		cont++;
	}	
	equi.close();
	return cont;
}

void separando_Datos(string equipos[][4])
{
	string linea,token;
	int i,j=0;;
	ifstream equi;
	equi.open("hola.csv");
	while(!equi.eof())
	{
		getline(equi,linea);
		istringstream iss(linea);
		i=0;
		while(getline(iss,token,';'))
		{
			equipos[j][i]=token;
			i++;
		}
		j++;

	}	
	equi.close();
}

int main(int argc, char* argv[])
{
	int n;
	n=cantidad_Equipos(argv[1]);
	cout<<n<<endl;
	string equipos[n][4];
	float distancias[n][n],dist,resta1,resta2;
	separando_Datos(equipos);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cout<<equipos[i][j];
		}
		cout<<endl;
	}

	//calcular_Distancias(equipos,distancias,n);

	for(int i=0;i<n;i++)
	{
		for (int j=0; j<n;j++)
		{
			if(i!=j)
			{
				resta1=strtof((equipos[i][2]).c_str(),0)-strtof((equipos[j][2]).c_str(),0);
				resta2=strtof((equipos[i][3]).c_str(),0)-strtof((equipos[j][3]).c_str(),0);
				dist= sqrt((pow(resta1,2))+(pow(resta2,2)));
				distancias[i][j]=dist;
			}
			else
			{
				distancias[i][j]=0;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout<<distancias[i][j]<<"   ";
		}
		cout<<endl;
	}
}