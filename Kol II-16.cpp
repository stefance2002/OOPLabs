#include<iostream>
#include<cstring>
using namespace std;

class Transport
{
protected:
    char destinacija[50];
    int cena, rastojanie;
public:
    Transport(const char *d="", int c=0, int r=0)
    {
        strcpy(destinacija, d);
        cena=c;
        rastojanie=r;
    }
    virtual int cenaTransport()=0;
    bool operator<(Transport &t)
    {
        return rastojanie<t.rastojanie;
    }
    char *getDestinacija()
    {
        return destinacija;
    }
    int getRastojanie()
    {
        return rastojanie;
    }
    friend ostream &operator<<(ostream &o, Transport &t)
    {
        return o << t.destinacija << " " << t.rastojanie << " " << t.cenaTransport() << endl;
    }
};

class AvtomobilTransport : public Transport
{
private:
    bool shofer;
public:
    AvtomobilTransport(const char *d="", int c=0, int r=0, bool s=false):Transport(d, c, r)
    {
        shofer=s;
    }
    int cenaTransport()
    {
        if(shofer)
        {
            return cena*1.2;
        }
        return cena;
    }
};

class KombeTransport : public Transport
{
private:
    int patnici;
public:
    KombeTransport(const char *d="", int c=0, int r=0, int s=0):Transport(d, c, r)
    {
        patnici=s;
    }
    int cenaTransport()
    {
        return cena-patnici*200;
    }
};

void pecatiPoloshiPonudi(Transport **t, int n, Transport &ponuda)
{
    Transport **temp=new Transport*[n];
    int j=0;
    for(int i=0; i<n; i++)
    {
        if(t[i]->cenaTransport()>ponuda.cenaTransport())
        {
            temp[j]=t[i];
            j++;
        }
    }
    for(int i = 0; i < j; i++)
    {
        for(int k = i + 1; k < j; k++)
        {
            if(*temp[k] < *temp[i])
            {
                swap(temp[k], temp[i]);
            }
        }
    }
    for(int i = 0; i < j; i++)
    {
        cout << *temp[i];
    }
}

int main(){

char destinacija[20];
int tip,cena,rastojanie,lugje;
bool shofer;
int n;
cin>>n;
Transport  **ponudi;
ponudi=new Transport *[n];

for (int i=0;i<n;i++){

    cin>>tip>>destinacija>>cena>>rastojanie;
    if (tip==1) {
        cin>>shofer;
        ponudi[i]=new AvtomobilTransport(destinacija,cena,rastojanie,shofer);

    }
    else {
        cin>>lugje;
        ponudi[i]=new KombeTransport(destinacija,cena,rastojanie,lugje);
    }


}

AvtomobilTransport nov("Ohrid",2000,600,false);
pecatiPoloshiPonudi(ponudi,n,nov);

for (int i=0;i<n;i++) delete ponudi[i];
delete [] ponudi;
return 0;
}
