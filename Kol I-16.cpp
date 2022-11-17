#include<iostream>
using namespace std;

struct rabotnanedela
{
    int n;
    int casovi[5];
};
typedef struct rabotnanedela rabotnanedela;

struct rabotnik
{
    char ime[50];
    rabotnanedela nedela[4];
};
typedef struct rabotnik rabotnik;

void tabela(rabotnik r[], int n)
{
    cout<<"TABLE\n"<<"Rab\t"<<"1\t"<<"2\t"<<"3\t"<<"4\t"<<"Vkupno"<<endl;
    int total=0, totalned=0;;
    for(int i=0; i<n; i++)
    {
        cout<<r[i].ime<<"\t";
        total=0;
        for(int j=0; j<4; j++)
        {
            totalned=0;
            for(int k=0; k<5; k++)
            {
                totalned+=r[i].nedela[j].casovi[k];
            }
            cout<<totalned<<"\t";
            total+=totalned;
        }
        cout<<total<<"\n";
    }
}

void maxnedela(rabotnik r[], int n)
{
    int maxx=0, maxI=0, j, k, vkupno;
    for(j=0; j<4; j++)
    {
        vkupno=0;
        for(k=0; k<5; k++)
        {
            vkupno+=r[n/2].nedela[j].casovi[k];
        }
        if(vkupno>maxx)
        {
            maxx=vkupno;
            maxI=j;
        }
        maxI++;
    }
    cout<<"MAX NEDELA NA RABOTNIK: "<<r[n/2].ime<<endl;
    cout<<maxI;
}

int main()
{
    int n;
    cin>>n;
    rabotnik r[20];

    for(int i=0; i<n; i++)
    {
        cin>>r[i].ime;
        for(int j=0; j<4; j++)
        {
            for(int k=0; k<5; k++)
            {
                cin>>r[i].nedela[j].casovi[k];
            }
        }
    }

    tabela(r, n);
    maxnedela(r, n);
    return 0;
}
