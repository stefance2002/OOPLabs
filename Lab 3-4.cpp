#include<iostream>
#include<cstring>
using namespace std;

class Masa
{
private:
    int dolzina, sirina;
public:
    Masa()
    {
        dolzina=1;
        sirina=1;
    }
    Masa(int d, int s)
    {
        dolzina=d;
        sirina=s;
    }
    void pecati()
    {
        cout<<" Masa: "<<dolzina<<" "<<sirina<<endl;
    }
};
class Soba
{
private:
    Masa m;
    int dolzina, sirina;
public:
    Soba()
    {
        dolzina=1;
        sirina=1;
    }
    Soba(int d, int s, Masa mm)
    {
        m=mm;
        dolzina=d;
        sirina=s;
    }
    void pecati()
    {
        cout<<" Soba: "<<dolzina<<" "<<sirina;
        m.pecati();
    }
};
class Kukja
{
private:
    Soba s;
    char adresa[50];
public:
    Kukja()
    {

    }
    Kukja(Soba ss, char *a)
    {
        s=ss;
        strcpy(adresa, a);
    }
    ~Kukja()
    {

    }
    void pecati()
    {
        cout<<"Adresa: "<<adresa;
        s.pecati();
    }
};

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	int masaSirina,masaDolzina;
        cin>>masaSirina;
        cin>>masaDolzina;
    	Masa m(masaSirina,masaDolzina);
    	int sobaSirina,sobaDolzina;
        cin>>sobaSirina;
        cin>>sobaDolzina;
    	Soba s(sobaSirina,sobaDolzina,m);
    	char adresa[30];
        cin>>adresa;
    	Kukja k(s,adresa);
    	k.pecati();
	}

    return 0;
}
