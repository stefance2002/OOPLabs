#include<iostream>
#include<cstring>
using namespace std;

class Lekar
{
protected:
    int fax;
    char ime[10];
    char prezime[11];
    double pplata;
public:
    Lekar(int fax=0, char*ime="", char*prezime="", double pplata=0)
    {
        this->fax=fax;
        strcpy(this->ime, ime);
        strcpy(this->prezime, prezime);
        this->pplata=pplata;
    }
    Lekar(const Lekar&l)
    {
        fax=l.fax;
        strcpy(ime, l.ime);
        strcpy(prezime, l.prezime);
        pplata=l.pplata;
    }
    void pecati()
    {
        cout<<fax<<": "<<ime<<" "<<prezime<<endl;
    }
    double plata()
    {
        return pplata;
    }
};

class MaticenLekar : public Lekar
{
private:
    int brPacienti;
    double *naplateni;
public:
    MaticenLekar(Lekar l=0, int br=0, double *n=0):Lekar(l)
    {
        brPacienti=br;
        naplateni=new double[br];
        for(int i=0; i<br; i++)
        {
            naplateni[i]=n[i];
        }
    }
    double prosekk()
    {
        double sum=0;
        for(int i=0; i<brPacienti; i++)
        {
            sum+=naplateni[i];
        }
        return sum/brPacienti;
    }
    void pecati()
    {
        Lekar::pecati();

        cout<<"Prosek na kotizacii: "<<prosekk()<<endl;
    }
    double plata()
    {
        return Lekar::plata()+prosekk()*0.3;
    }

};

int main() {
	int n;
	cin>>n;
	int pacienti;
	double kotizacii[100];
	int faksimil;
	char ime [20];
	char prezime [20];
	double osnovnaPlata;

	Lekar * lekari = new Lekar [n];
	MaticenLekar * maticni = new MaticenLekar [n];

	for (int i=0;i<n;i++){
		cin >> faksimil >> ime >> prezime >> osnovnaPlata;
		lekari[i] = Lekar(faksimil,ime,prezime,osnovnaPlata);
	}

	for (int i=0;i<n;i++){
		cin >> pacienti;
		for (int j=0;j<pacienti;j++){
			cin >> kotizacii[j];
		}
		maticni[i]=MaticenLekar(lekari[i],pacienti,kotizacii);
	}

	int testCase;
	cin>>testCase;

	if (testCase==1){
		cout<<"===TESTIRANJE NA KLASATA LEKAR==="<<endl;
		for (int i=0;i<n;i++){
			lekari[i].pecati();
			cout<<"Osnovnata plata na gorenavedeniot lekar e: "<<lekari[i].plata()<<endl;
		}
	}
	else {
		cout<<"===TESTIRANJE NA KLASATA MATICENLEKAR==="<<endl;
		for (int i=0;i<n;i++){
			maticni[i].pecati();
			cout<<"Platata na gorenavedeniot maticen lekar e: "<<maticni[i].plata()<<endl;
		}
	}

	delete [] lekari;
	delete [] maticni;

	return 0;
}
