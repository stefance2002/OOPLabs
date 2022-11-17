#include<iostream>
#include<cstring>
using namespace std;

struct Laptop
{
    char firma[100];
    float inch;
    bool touch;
    int cena;
};
typedef struct Laptop Laptop;

struct ITStore
{
    char ime[100];
    char lokacija[100];
    Laptop laptopi[100];
    int n;
};
typedef struct ITStore ITStore;

void print(ITStore stores[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<stores[i].ime<<" "<<stores[i].lokacija<<endl;
        for(int j=0; j<stores[i].n; j++)
        {
            cout<<stores[i].laptopi[j].firma<<" ";
            cout<<stores[i].laptopi[j].inch<<" ";
            cout<<stores[i].laptopi[j].cena<<endl;
        }
    }
}

void najeftinaponuda(ITStore stores[], int n)
{
    int najeftina, I, J, flag=1;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<stores[i].n; j++)
        {
            if(flag)
            {
                if(stores[i].laptopi[j].touch)
                {
                    najeftina=stores[i].laptopi[j].cena;
                    I=i;
                    J=j;
                    flag=0;
                }
            }
            if(stores[i].laptopi[j].touch &&(stores[i].laptopi[j].cena<najeftina))
            {
                najeftina=stores[i].laptopi[j].cena;
                I=i;
                J=j;
            }
        }
    }
    cout<<"Najeftina ponuda ima prodavnicata:"<<endl;
    cout<<stores[I].ime<<" "<<stores[I].lokacija<<endl;
    cout<<"Najniskata cena iznesuva: "<<stores[I].laptopi[J].cena;
}

int main() {
    ITStore stores[100];
    int n;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin>>stores[i].ime>>stores[i].lokacija>>stores[i].n;
        for(int j=0; j<stores[i].n; j++)
        {
            cin>>stores[i].laptopi[j].firma;
            cin>>stores[i].laptopi[j].inch;
            cin>>stores[i].laptopi[j].touch;
            cin>>stores[i].laptopi[j].cena;
        }
    }

    print(stores, n);
    najeftinaponuda(stores, n);

    return 0;
}
