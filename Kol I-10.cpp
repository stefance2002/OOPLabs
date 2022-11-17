#include<iostream>
#include<cstring>
using namespace std;

struct Igrac
{
    char ime[15];
    int nivo;
    int poeni;
};
typedef struct Igrac Igrac;

struct Igra
{
    char ime[20];
    Igrac igraci[30];
    int n;
};
typedef struct Igra Igra;

void najdobarigrac(Igra igra[], int n)
{
    int maxigraci=igra[0].n, I=0;
    for(int i=0; i<n; i++)
    {
        if(igra[i].n>maxigraci)
        {
            maxigraci=igra[i].n;
            I=i;
        }
    }
    int maxpoeni=igra[I].igraci[0].poeni, J=0;

        for(int j=0; j<igra[I].n; j++)
        {
            if(igra[I].igraci[j].poeni>maxpoeni)
            {
                maxpoeni=igra[I].igraci[j].poeni;
                J=j;
            }
            else if(igra[I].igraci[j].poeni==maxpoeni)
            {
                if(igra[I].igraci[j].nivo>igra[I].igraci[J].nivo)
                {
                    maxpoeni=igra[I].igraci[j].poeni;
                    J=j;
                }
            }
        }
    cout<<"Najdobar igrac e igracot so korisnicko ime "<<igra[I].igraci[J].ime<<" koj ja igra igrata "<<igra[I].ime;
}

int main()
{
    int n;
    Igra igra[10];
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>igra[i].ime>>igra[i].n;
        for(int j=0; j<igra[i].n; j++)
        {
            cin>>igra[i].igraci[j].ime;
            cin>>igra[i].igraci[j].nivo;
            cin>>igra[i].igraci[j].poeni;
        }
    }

    najdobarigrac(igra, n);

    return 0;
}
