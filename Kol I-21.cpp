#include<iostream>
#include<cstring>
using namespace std;

struct Tanc
{
    char ime[15];
    char zemja[15];
};
typedef struct Tanc Tanc;

struct Tancer
{
    char ime[20];
    char prezime[20];
    Tanc tanci[5];
};
typedef struct Tancer Tancer;

void tancuvanje(Tancer t[], int n, char zemja[])
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(strcmp(t[i].tanci[j].zemja, zemja)==0)
            {
                cout<<t[i].ime<<" "<<t[i].prezime<<", "<<t[i].tanci[j].ime<<endl;
                break;
            }
        }
    }
}

int main()
{
    int n;
    char zemja[15];
    cin>>n;
    Tancer t[10];

    for(int i=0; i<n; i++)
    {
        cin>>t[i].ime>>t[i].prezime;
        for(int j=0; j<3; j++)
        {
            cin>>t[i].tanci[j].ime>>t[i].tanci[j].zemja;
        }
    }

    cin>>zemja;
    tancuvanje(t, n, zemja);

    return 0;
}
