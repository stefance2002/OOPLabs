#include<iostream>
#include<cstring>
using namespace std;

enum zanr{akcija, komedija, drama};

class Film
{
private:
    char *ime;
    int memorija;
    zanr tip;
public:
    Film(char *ime="", int memorija=0, zanr tip=(zanr)0)
    {
        this->ime=new char[strlen(ime)+1];
        strcpy(this->ime, ime);
        this->memorija=memorija;
        this->tip=tip;
    }
    Film(const Film &f)
    {
        ime=new char[strlen(f.ime)+1];
        strcpy(ime, f.ime);
        memorija=f.memorija;
        tip=f.tip;
    }
    ~Film()
    {
        delete[]ime;
    }
    Film &operator=(const Film &f)
    {
        if(this!=&f)
        {
            delete[]ime;
            ime=new char[strlen(f.ime)+1];
            strcpy(ime, f.ime);
            memorija=f.memorija;
            tip=f.tip;
        }
        return *this;
    }
    void pecati()
    {
        cout<<memorija<<"MB"<< "-" << '"' << ime << '"' << endl;
    }
    int getMemorija()
    {
        return memorija;
    }
    zanr getTip()
    {
        return tip;
    }
};

class DVD
{
private:
    Film f[5];
    int n;
    int kapacitet;
public:
    DVD(Film filmovi[]=0, int br=0, int k=0)
    {
        n=br;
        kapacitet=k;
        for(int i=0; i<n; i++)
        {
            f[i]=filmovi[i];
        }

    }
    DVD(int g = 0)
    {
        n= 0;
        kapacitet= g;
    }
    DVD(const DVD &d)
    {
        n=d.n;
        kapacitet=d.kapacitet;
        for(int i=0; i<n; i++)
        {
            f[i]=d.f[i];
        }

    }
    int getMemory()
    {
        int sum=0;
        for(int i=0; i<n; i++)
        {
            sum+=f[i].getMemorija();
        }
        return sum;
    }
    void dodadiFilm (Film f1)
    {
        if(n<5 && (getMemory()-kapacitet>=f1.getMemorija()))
        {
            f[n++]=f1;
        }
    }
    void pecatiFilmoviDrugZanr(zanr z)
    {
        for(int i = 0; i <n; i++)
        {
            if(f[i].getTip()!= z)
            {
                f[i].pecati();
            }
        }
    }
    Film getFilm(int i)
    {
        return f[i];
    }
    int getBroj()
    {
        return n;
    }
    float procentNaMemorijaOdZanr (zanr z)
    {
        int zanrSum = 0;
        for(int i = 0; i<n; i++)
        {
            if(f[i].getTip() == z)
            {
                zanrSum += f[i].getMemorija();
            }
        }
        return (float)zanrSum/getMemory() * 100;
    }
};

int main() {
    // se testira zadacata modularno
    int testCase;
    cin >> testCase;

    int n, memorija, kojzanr;
    char ime[50];

    if (testCase == 1) {
        cout << "===== Testiranje na klasata Film ======" << endl;
        cin >> ime;
        cin >> memorija;
        cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
        Film f(ime, memorija, (zanr) kojzanr);
        f.pecati();
    } else if (testCase == 2) {
        cout << "===== Testiranje na klasata DVD ======" << endl;
        DVD omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        for (int i = 0; i < n; i++)
            (omileno.getFilm(i)).pecati();
    } else if (testCase == 3) {
        cout << "===== Testiranje na metodot dodadiFilm() od klasata DVD ======" << endl;
        DVD omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        for (int i = 0; i < omileno.getBroj(); i++)
            (omileno.getFilm(i)).pecati();
    } else if (testCase == 4) {
        cout << "===== Testiranje na metodot pecatiFilmoviDrugZanr() od klasata DVD ======" << endl;
        DVD omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        cin >> kojzanr;
        omileno.pecatiFilmoviDrugZanr((zanr) kojzanr);

    } else if (testCase == 5) {
        cout << "===== Testiranje na metodot pecatiFilmoviDrugZanr() od klasata DVD ======" << endl;
        DVD omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        cin >> kojzanr;
        omileno.pecatiFilmoviDrugZanr((zanr) kojzanr);

    } else if (testCase == 6){
		cout<<"===== Testiranje na metodot procentNaMemorijaOdZanr() od klasata DVD =====" <<endl;
		DVD omileno(40);
		cin >> n;
		for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        cin >> kojzanr;
        cout<<"Procent na filmovi od dadeniot zanr iznesuva: "<<omileno.procentNaMemorijaOdZanr((zanr) kojzanr)<<"%\n";

	}

    return 0;
}
