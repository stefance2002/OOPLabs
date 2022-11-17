#include<iostream>
#include<cstring>
using namespace std;

class Vozac
{
protected:
    char ime[100];
    int vozrast;
    int trki;
    bool veteran;
public:
    Vozac(const char *ime2="", int vozrast2=0, int trki2=0, bool veteran2=false)
    {
        strcpy(ime, ime2);
        vozrast=vozrast2;
        trki=trki2;
        veteran=veteran2;
    }
    friend ostream &operator<<(ostream &out, Vozac &v)
    {
        out<<v.ime<<endl;
        out<<v.vozrast<<endl;
        out<<v.trki<<endl;
        if(v.veteran)
        {
            cout<<"VETERAN"<<endl;
        }
    }
    virtual double zarabotuvacka() = 0;
    virtual double danok() = 0;
    bool operator==(Vozac &v)
    {
        return zarabotuvacka()==v.zarabotuvacka();
    }
};

class Avtomobilist : public Vozac
{
private:
    float cena;
public:
    Avtomobilist(const char *ime2="", int vozrast2=0, int trki2=0, bool veteran2=false, float cena2=0):Vozac(ime2, vozrast2, trki2, veteran2)
    {
        cena=cena2;
    }
    double zarabotuvacka()
    {
        return cena/5;
    }
    double danok()
    {
        if(trki>10)
        {
            return zarabotuvacka()*0.15;
        }
        else
        {
            return zarabotuvacka()*0.1;
        }
    }
};

class Motociklist : public Vozac
{
private:
    int moknost;
public:
    Motociklist(const char *ime2="", int vozrast2=0, int trki2=0, bool veteran2=false, int moknost2=0):Vozac(ime2, vozrast2, trki2, veteran2)
    {
        moknost=moknost2;
    }
    double zarabotuvacka()
    {
        return moknost*20;
    }
    double danok()
    {
        if(veteran)
        {
            return zarabotuvacka()*0.25;
        }
        else
        {
            return zarabotuvacka()*0.2;
        }
    }
};

int soIstaZarabotuvachka(Vozac **v, int n, Vozac *vv)
{
    int brojac=0;
    for(int i=0; i<n; i++)
    {
        if(*v[i]==*vv)
        {
            brojac++;
        }
    }
    return brojac;
}

int main() {
	int n, x;
	cin >> n >> x;
	Vozac **v = new Vozac*[n];
	char ime[100];
	int vozrast;
	int trki;
	bool vet;
	for(int i = 0; i < n; ++i) {
		cin >> ime >> vozrast >> trki >> vet;
		if(i < x) {
			float cena_avto;
			cin >> cena_avto;
			v[i] = new Avtomobilist(ime, vozrast, trki, vet, cena_avto);
		} else {
			int mokjnost;
			cin >> mokjnost;
			v[i] = new Motociklist(ime, vozrast, trki, vet, mokjnost);
		}
	}
	cout << "=== DANOK ===" << endl;
	for(int i = 0; i < n; ++i) {
		cout << *v[i];
		cout << v[i]->danok() << endl;
	}
	cin >> ime >> vozrast >> trki >> vet;
	int mokjnost;
	cin >> mokjnost;
	Vozac *vx = new Motociklist(ime, vozrast, trki, vet, mokjnost);
	cout << "=== VOZAC X ===" << endl;
	cout << *vx;
	cout << "=== SO ISTA ZARABOTUVACKA KAKO VOZAC X ===" << endl;
	cout << soIstaZarabotuvachka(v, n, vx);
    for(int i = 0; i < n; ++i) {
        delete v[i];
    }
    delete [] v;
    delete vx;
	return 0;
}
