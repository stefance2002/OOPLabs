#include<iostream>
using namespace std;

class Vozilo
{
protected:
    double masa;
    int sirina, visina;
public:
    Vozilo(double m, int s, int v)
    {
        masa=m;
        sirina=s;
        visina=v;
    }
    double getMasa()
    {
        return masa;
    }
    int getSirocina()
    {
        return sirina;
    }
    virtual int tip()=0;
    virtual int vratiDnevnaCena()=0;
};

class Avtomobil : public Vozilo
{
private:
    int vrati;
public:
    Avtomobil(double m=0, int s=0, int v=0, int vr=0) : Vozilo(m, s, v)
    {
        vrati=vr;
    }
    int tip()
    {
        return 1;
    }
    int vratiDnevnaCena()
    {
        if(vrati<5)
        {
            return 100;
        }
        return 130;
    }
};

class Avtobus : public Vozilo
{
private:
    int patnici;
public:
    Avtobus(double m=0, int s=0, int v=0, int p=0) : Vozilo(m, s, v)
    {
        patnici=p;
    }
    int tip()
    {
        return 2;
    }
    int vratiDnevnaCena()
    {
        return 5*patnici;
    }
};

class Kamion : public Vozilo
{
private:
    double maxMasa;
public:
    Kamion(double m=0, int s=0, int v=0, double mm=0) : Vozilo(m, s, v)
    {
        maxMasa=mm;
    }
    int tip()
    {
        return 3;
    }
    int vratiDnevnaCena()
    {
        return (getMasa()+maxMasa)*0.02;
    }
};

class ParkingPlac
{
private:
    Vozilo **vozila;
    int n;
public:
    ParkingPlac()
    {
        n=0;
        vozila=new Vozilo*[n];
        vozila=0;
    }
    ~ParkingPlac()
    {
        delete[]vozila;
    }
    ParkingPlac &operator+=(Vozilo*v)
    {
        Vozilo**temp=new Vozilo*[n+1];
        for(int i=0; i<n; i++)
        {
            temp[i]=vozila[i];
        }
        delete[]vozila;
        vozila=temp;
        vozila[n++]=v;
        return *this;
    }
    float presmetajVkupnaMasa()
    {
        float sum=0;
        for(int i=0; i<n; i++)
        {
            sum+=vozila[i]->getMasa();
        }
        return sum;
    }
    int brojVozilaPoshirokiOd(int l)
    {
        int sum=0;
        for(int i=0; i<n; i++)
        {
            if(vozila[i]->getSirocina()>l)
            {
                sum++;
            }
        }
        return sum;
    }
    void pecati()
    {
        int av=0, a=0, k=0;
        for(int i=0; i<n; i++)
        {
            if(vozila[i]->tip()==1)
            {
                av++;
            }
            else if(vozila[i]->tip()==2)
            {
                a++;
            }
            else
            {
                k++;
            }
        }
        cout<<"Brojot na avtomobili e "<<av<<
        ", brojot na avtobusi e "<<a<<" i brojot na kamioni e "<<k<<"."<<endl;
    }
     int pogolemaNosivostOd(Vozilo& v)
     {
         int k=0;
         for(int i=0; i<n; i++)
        {
            if(vozila[i]->tip()==3)
            {
                if(vozila[i]->getMasa()>v.getMasa())
                {
                    k++;
                }
            }
        }
        return k;
     }
     int vratiDnevnaZarabotka()
     {
         int suma=0;
         for(int i=0; i<n; i++)
         {
             suma+=vozila[i]->vratiDnevnaCena();
         }
         return suma;
     }
};

int main(){
ParkingPlac p;

int n;
cin>>n;
int shirina,visina, broj;
float masa,nosivost;
for (int i=0;i<n;i++){
    int type;
    cin>>type;
    if(type==1){
        cin>>masa>>shirina>>visina>>broj;
        Avtomobil *a=new Avtomobil(masa,shirina,visina,broj);
        p+=a;
    }
    if(type==2){
        cin>>masa>>shirina>>visina>>broj;
        p+=new Avtobus(masa,shirina,visina,broj);
    }
    if(type==3){
        cin>>masa>>shirina>>visina>>nosivost;
        p+=new Kamion(masa,shirina,visina,nosivost);
    }
}
p.pecati();
cout<<"\nZarabotkata e "<<p.vratiDnevnaZarabotka()<<endl;
cout<<"Vkupnata masa e "<<p.presmetajVkupnaMasa()<<endl;
cout<<"Brojot poshiroki od 5 e "<<p.brojVozilaPoshirokiOd(5)<<endl;
Avtomobil a(1200,4,3,5);
cout<<"Brojot na kamioni so nosivost pogolema od avtomobilot e "<<p.pogolemaNosivostOd(a)<<endl;

}
