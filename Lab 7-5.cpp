#include<iostream>
#include<cstring>
using namespace std;

class ZicanInstrument
{
protected:
    char ime[20];
    int zici;
    float price;
public:
    ZicanInstrument(char *i="", int z=0, float c=0)
    {
        strcpy(ime, i);
        zici=z;
        price=c;
    }
    virtual float cena()=0;
    bool operator==(ZicanInstrument &v)
    {
        if(zici==v.zici)
        {
            return 1;
        }
        return 0;
    }
    friend ostream &operator<<(ostream &out, const ZicanInstrument&v)
    {
        out<<v.ime<<" "<<v.zici<<" "<<v.price<<endl;
        return out;
    }
};

class Mandolina : public ZicanInstrument
{
private:
    char forma[20];
public:
    Mandolina(char *i="", int z=0, float c=0, char *f=""):ZicanInstrument(i, z, c)
    {
        strcpy(forma, f);
    }
    float cena()
    {
        if(strcmp(forma, "Neapolitan")==0)
        {
            return price*1.15;
        }
        return price;
    }
};

class Violina : public ZicanInstrument
{
private:
    float golemina;
public:
    Violina(char *i="", int z=0, float c=0, float g=0):ZicanInstrument(i, z, c)
    {
        golemina=g;
    }
    float cena()
    {
        if(golemina==0.25)
        {
            return price*1.1;
        }
        else if(golemina==1.00)
        {
            return price*1.2;
        }
        return price;
    }
};

void pecatiInstrumenti(ZicanInstrument &zi, ZicanInstrument **z, int n)
{
    for(int i=0; i<n; i++)
    {
        if(zi==*z[i])
        {
            cout<<z[i]->cena()<<endl;
        }
    }
}

int main() {
	char ime[20];
	int brojZici;
	float cena;
	char forma[20];
	cin >> ime >> brojZici >> cena >> forma;
	Mandolina m(ime, brojZici, cena, forma);
	int n;
	cin >> n;
	ZicanInstrument **zi = new ZicanInstrument*[2 * n];
	for(int i = 0; i < n; ++i) {
		cin >> ime >> brojZici >> cena >> forma;
		zi[i] = new Mandolina(ime, brojZici, cena, forma);
	}
	for(int i = 0; i < n; ++i) {
		float golemina;
		cin >> ime >> brojZici >> cena >> golemina;
		zi[n + i] = new Violina(ime, brojZici, cena, golemina);
	}
	pecatiInstrumenti(m, zi, 2 * n);
	for(int i = 0; i < 2 * n; ++i) {
		delete zi[i];
	}
	delete [] zi;
	return 0;
}
