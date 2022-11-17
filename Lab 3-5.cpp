#include<iostream>
#include<cstring>
using namespace std;

class Rabotnik
{
private:
    char ime[30];
    char prezime[30];
    int plata;
public:
    Rabotnik()
    {

    }
    Rabotnik(char *i, char *p, int pla)
    {
        strcpy(ime, i);
        strcpy(prezime, p);
        plata=pla;
    }
     int getplata()
    {
        return plata;
    }
    void pecati()
    {
        cout<<ime<<" "<<prezime<<" "<<plata<<endl;
    }
};
class Fabrika
{
private:
    Rabotnik rabotnik[100];
    int vraboteni;
public:
    Fabrika()
    {

    }
    Fabrika(Rabotnik r[], int n)
    {
        vraboteni=n;
        for(int i=0; i<vraboteni; i++)
        {
            rabotnik[i]=r[i];
        }
    }
    void pecativraboteni()
    {
        cout<<"Site vraboteni:"<<endl;
        for(int i=0; i<vraboteni; i++)
        {
            rabotnik[i].pecati();
        }
    }
    void pecatisoplata(int minplata)
    {
        cout<<"Vraboteni so plata povisoka od "<<minplata<<" :"<<endl;
        for(int i=0; i<vraboteni; i++)
        {
            if(minplata<=rabotnik[i].getplata())
            {
                rabotnik[i].pecati();
            }
        }
    }
};
int main()
{
    int n;
    cin>>n;
    char ime[30], prezime[30];
    int plata, minplata;
    Rabotnik rab[100];
    for(int i=0; i<n; i++)
    {
        cin>>ime>>prezime>>plata;
        rab[i]=Rabotnik(ime, prezime, plata);
    }
    Fabrika fabrika(rab, n);
    fabrika.pecativraboteni();
    cin>>minplata;
    fabrika.pecatisoplata(minplata);

    return 0;
}
