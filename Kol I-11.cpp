#include<iostream>
#include<cstring>
using namespace std;

class Pica
{
private:
    char ime[15];
    int cena;
    char *sostojki;
    int namaluvanje;
public:
    Pica(char *ime="", int cena=0, char *sostojki="", int namaluvanje=0)
    {
        strcpy(this->ime, ime);
        this->cena=cena;
        this->namaluvanje=namaluvanje;
        this->sostojki=new char[strlen(sostojki)+1];
        strcpy(this->sostojki, sostojki);
    }
    Pica(const Pica&p)
    {
        strcpy(ime, p.ime);
        cena=p.cena;
        namaluvanje=p.namaluvanje;
        sostojki=new char[strlen(p.sostojki)+1];
        strcpy(sostojki, p.sostojki);
    }
    Pica &operator=(const Pica &p)
    {
        if(this!=&p)
        {
            strcpy(ime, p.ime);
            cena=p.cena;
            namaluvanje=p.namaluvanje;
            delete[]sostojki;
            sostojki=new char[strlen(p.sostojki)+1];
            strcpy(sostojki, p.sostojki);
        }
        return *this;
    }
    ~Pica()
    {
        delete []sostojki;
    }
    void pecati()
    {
        cout<<ime<<" - "<<sostojki<<", "<<cena;
    }
    bool istiSe(Pica p)
    {
        return strcmp(sostojki, p.sostojki)==0;
    }
    int getnamaluvanje()
    {
        return namaluvanje;
    }
    int getCena()
    {
        return cena;
    }
};

class Picerija
{
private:
    char ime[15];
    Pica *pici;
    int n;
public:
    Picerija(const char *ime="")
    {
        strncpy(this->ime, ime, 14);
        this->ime[14]=0;
        pici=NULL;
        n=0;
    }
    ~Picerija()
    {
        delete[]pici;
    }
    Picerija(const char *ime, Pica* pici, int br)
    {
        strncpy(this->ime, ime, 14);
        this->ime[14]=0;
        this->n=n;
        delete[]pici;
        this->pici=new Pica[n];
        for(int i=0; i<n; i++)
        {
            this->pici[i]=pici[i];
        }
    }
    Picerija(const Picerija &p)
    {
		strcpy(ime, p.ime);
		n = p.n;
		pici = new Pica[n];
		for (int i = 0; i <n; i++)
			pici[i] = p.pici[i];
	}
    Picerija &operator=(const Picerija &p)
    {
        if(this!=&p)
        {
            strcpy(this->ime, p.ime);
            n=p.n;
            delete[]pici;
            pici=new Pica[n];
            for(int i=0; i<n; i++)
            {
                pici[i]=p.pici[i];
            }
        }
        return *this;
    }
    Picerija& operator+=(Pica &p){
		bool imaIsta = false;
		for (int i = 0; i < n; i++)
			if (pici[i].istiSe(p))
				imaIsta = true;
		if (!imaIsta)
		{
			Pica* tmp = new Pica[n + 1];
			for (int i = 0; i < n; i++)
				tmp[i] = pici[i];
			tmp[n++] = p;
			delete[] pici;
			pici = tmp;
		}
		return *this;
	}
	void setIme(const char*ime)
	{
	    strncpy(this->ime, ime, 14);
	    this->ime[14]=0;
	}
	char *getIme()
	{
	    return ime;
	}
	void piciNaPromocija()
	{
	    for(int i=0; i<n; i++)
        {
            if(pici[i].getnamaluvanje()!=0)
            {
                pici[i].pecati();
                cout << " " <<
                pici[i].getCena() * (1 - pici[i].getnamaluvanje() / 100.0) << endl;
            }
        }
	}
};

int main() {

	int n;
	char ime[15];
	cin >> ime;
	cin >> n;

	Picerija p1(ime);
	for (int i = 0; i < n; i++){
		char imp[100];
		cin.get();
		cin.getline(imp, 100);
		int cena;
		cin >> cena;
		char sostojki[100];
		cin.get();
		cin.getline(sostojki, 100);
		int popust;
		cin >> popust;
		Pica p(imp, cena, sostojki, popust);
		p1+=p;
	}

	Picerija p2 = p1;
	cin >> ime;
	p2.setIme(ime);
	char imp[100];
	cin.get();
	cin.getline(imp, 100);
	int cena;
	cin >> cena;
	char sostojki[100];
	cin.get();
	cin.getline(sostojki, 100);
	int popust;
	cin >> popust;
	Pica p(imp, cena, sostojki, popust);
	p2+=p;

	cout << p1.getIme() << endl;
	cout << "Pici na promocija:" << endl;
	p1.piciNaPromocija();

	cout << p2.getIme() << endl;
	cout << "Pici na promocija:" << endl;
	p2.piciNaPromocija();

	return 0;
}
