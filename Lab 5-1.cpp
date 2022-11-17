#include<iostream>
#include<cstring>
using namespace std;

class Automobile
{
private:
    char*marka;
    int *registracija;
    int brzina;
public:
    Automobile(char*marka="", int *registracija=0, int brzina=0)
    {
        this->marka=new char[strlen(marka)+1];
        strcpy(this->marka, marka);
        this->registracija=new int[5];

        if(registracija!=0)
        {
            for(int i=0; i<5; i++)
            {
                this->registracija[i]=registracija[i];
            }
        }
        this->brzina=brzina;
    }
    Automobile(const Automobile &a)
    {
        marka=new char[strlen(a.marka)+1];
        strcpy(marka, a.marka);
        registracija=new int[5];
        for(int i=0; i<5; i++)
        {
            registracija[i]=a.registracija[i];
        }
        brzina=a.brzina;
    }
    ~Automobile()
    {
        delete [] registracija;
        delete [] marka;
    }
    bool operator==(const Automobile&a)
    {
        for(int i=0; i<5; i++)
        {
            if(registracija[i]!=a.registracija[i])
            {
                return false;
            }
        }
        return true;
    }
    friend ostream &operator<<(ostream &out, const Automobile &a)
    {
        out<<"Marka\t"<<a.marka<<"\tRegistracija[ ";
        for(int i=0; i<5; i++)
        {
            out<<a.registracija[i]<<" ";
        }
        out<<"]";
        return out;
    }
    Automobile &operator=(const Automobile &a)
    {
        if(this != &a)
        {
            delete []registracija;
            delete []marka;
            registracija = new int[5];
            marka=new char[strlen(a.marka) + 1];
            for(int i=0; i<5; i++)
            {
                registracija[i]=a.registracija[i];
            }
            brzina=a.brzina;
            strcpy(marka, a.marka);
        }
        return *this;
    }
    int getBrzina()
    {
        return brzina;
    }
};

class RentACar
{
private:
    char ime[100];
    Automobile *koli;
    int n;
public:
    RentACar(char *ime="")
    {
        strcpy(this->ime, ime);
        koli=new Automobile[0];
        n=0;
    }
    RentACar &operator+=(const Automobile &a)
    {
        Automobile *temp=new Automobile[n+1];
        for(int i=0; i<n; i++)
        {
            temp[i]=koli[i];
        }
        delete[]koli;
        koli=temp;
        koli[n++]=a;
        return *this;
    }
    RentACar &operator-=(const Automobile &a)
    {
        Automobile *temp=new Automobile[n-1];
        int j=0;
        for(int i=0; i<n; i++)
        {
            if(koli[i]==a)
            {

            }
            else
            {
                temp[j]=koli[i];
                j++;
            }
        }
        n=j;
        delete[]koli;
        koli=temp;

    }
     void pecatiNadBrzina(int max)
     {
         cout<<ime<<endl;
         for(int i=0; i<n; i++)
         {
             if(koli[i].getBrzina()>max)
             {
                 cout<<koli[i];
             }
         }
     }
};

int main()
{
   RentACar agencija("FINKI-Car");
   int n;
   cin>>n;

   for (int i=0;i<n;i++)
   {
    	char marka[100];
    	int regisracija[5];
    	int maximumBrzina;

       	cin>>marka;

       	for (int i=0;i<5;i++)
    		cin>>regisracija[i];

    	cin>>maximumBrzina;

       	Automobile nov=Automobile(marka,regisracija,maximumBrzina);

    	//dodavanje na avtomobil
       	agencija+=nov;

   }
    //se cita grehsniot avtmobil, za koj shto avtmobilot so ista registracija treba da se izbrishe
    char marka[100];
    int regisracija[5];
    int maximumBrzina;
    cin>>marka;
    for (int i=0;i<5;i++)
    cin>>regisracija[i];
    cin>>maximumBrzina;

    Automobile greshka=Automobile(marka,regisracija,maximumBrzina);

    //brishenje na avtomobil
    agencija-=greshka;

    agencija.pecatiNadBrzina(150);

    return 0;
}
