#include<iostream>
#include<cstring>
using namespace std;

struct Voz
{
    char relacija [50];
    float distanca;
    int patnici;
};
typedef struct Voz Voz;

struct Stanica
{
    char grad[20];
    Voz vozovi[30];
    int n;
};
typedef struct Stanica Stanica;

void najkratkarelacija(Stanica stanica[], int n, char grad[])
{
    int i, j, I, J, flag=1;
    float minkm;
    for(i=0; i<n; i++)
    {
        if(strcmp(grad, stanica[i].grad)==0)
        {
            if(flag)
            {
                minkm=stanica[i].vozovi[0].distanca;
                I=i;
                J=j;
                flag=0;
            }
            for(j=0; j<stanica[i].n; j++)
            {
                if(stanica[i].vozovi[j].distanca<=minkm)
                {
                    minkm=stanica[i].vozovi[j].distanca;
                    I=i;
                    J=j;
                }
            }
            cout<<"Najkratka relacija: "<<stanica[I].vozovi[J].relacija<<" ("<<stanica[I].vozovi[J].distanca<<" km)";
            return ;
        }
    }
}

int main(){

    int n;
	cin>>n;

    Stanica stanica[100];
    for (int i=0; i<n; i++)
    {
        cin>>stanica[i].grad>>stanica[i].n;
        for(int j=0; j<stanica[i].n; j++)
        {
            cin>>stanica[i].vozovi[j].relacija;
            cin>>stanica[i].vozovi[j].distanca;
            cin>>stanica[i].vozovi[j].patnici;
        }
    }

    char grad[25];
    cin>>grad;
	najkratkarelacija(stanica, n, grad);
	return 0;
}
