#include<iostream>
#include<cstring>
using namespace std;

class Igrachka {
public:
    Igrachka()
    {

    }
    virtual float getVolumen() = 0;
    virtual float getMasa() = 0;
    virtual float getPlostina()=0;
    //дополнително барање 1
};

class Forma{
protected:
    char boja[100];
    int gustina;
public:
    // да се имплементираат потребните методи
    Forma(char *ime="", int g=0)
    {
        strcpy(boja, ime);
        gustina=g;
    }
};

class Topka : public Igrachka, public Forma
{
private:
    int r;
public:
    Topka(char *ime="", int g=0, int rr=0):Forma(ime, g)
    {
        r=rr;
    }
    float getVolumen()
    {
        return (float)4/3*3.14*r*r*r;
    }
    float getMasa()
    {
        return getVolumen()*gustina;
    }
};

class Kocka : public Igrachka, public Forma
{
private:
    int sirina, visina, dolzina;
public:
    Kocka(char *ime="", int g=0, int v=0, int d=0, int s=0):Forma(ime, g)
    {
        sirina=s;
        visina=v;
        dolzina=d;
    }
    float getVolumen()
    {
        return sirina*visina*dolzina;
    }
    float getMasa()
    {
        return getVolumen()*gustina;
    }

};

int main(){
	//vnesi informacii za kupche

    int n;
    char ime[100];
    int sirina, visina, dolzina, radius, gustina, testcase;
    cin>>n;
    Igrachka kupche[n];
    //vnesi informacii za igrachkata na Petra
    for(int i=0; i<n; i++)
    {
        cin>>testcase;
        if(testcase==1)
        {
            cin>>ime>>gustina>>radius;
            kupche[i]=Topka(ime, gustina, radius);
        }
        else
        {
            cin>>ime>>gustina>>sirina>>visina>>dolzina;
            kupche=new Kocka(ime, gustina, sirina, visina, dolzina);
        }
    }
    cin>>ime>>gustina>>sirina>>visina>>dolzina;
    Kocka petra(ime, gustina, sirina, visina, dolzina);

    float sum=0, maks=0;
    for(int i=0; i<n; i++)
    {
        sum+=kupche[i].getMasa();
        if(kupche[i].getMasa()>maks)
        {
            maks=kupche[i].getMasa();
        }
    }
    if(sum>petra.getMasa())
    {
        cout<<"DA"<<endl;
    }
    else
    {
        cout<<"NE"<<endl;
    }
    if(maks>petra.getMasa())
    {
        cout<<"Razlikata e: "<<maks-petra.getMasa()<<endl;
    }
    else
    {
        cout<<"Razlikata e: "<<petra.getMasa()-maks<<endl;
    }
	//baranje 1


	//baranje 2

    //дополнително барање 2

	return 0;
}
