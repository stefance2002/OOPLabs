#include<iostream>
#include<cstring>

using namespace std;

class Avtomobil
{
private:
    char boja[20];
    char brend[20];
    char model[20];
public:
    Avtomobil(char *b="", char *br="", char *m="")
    {
        strncpy(boja, b, 20);
        strncpy(brend, br, 20);
        strncpy(model, m, 20);
    }
    Avtomobil &operator=(const Avtomobil &a)
    {
       if(this != &a)
        {
            strncpy(boja, a.boja, 20);
            strncpy(brend, a.brend, 20);
            strncpy(model, a.model, 20);
        }
        return *this;
    }
    ~Avtomobil()
    {

    }
    char*getBrend()
    {
        return brend;
    }
    char*getBoja()
    {
        return boja;
    }
    char*getModel()
    {
        return model;
    }
};

class ParkingPlac
{
private:
    char adresa[20];
    char *id;
    int cena;
    int zarabotka;
    Avtomobil *koli;
    int n;
public:
    ParkingPlac(char *a, char *i, int c)
    {
        strncpy(adresa, a, 20);
        id = new char[strlen(i) + 1];
        strcpy(id, i);
        cena = c;
        n = 0;
    }

    ParkingPlac()
    {
        strncpy(adresa, "", 20);
        id = new char[0];
        cena = 0;
        n = 0;
    }
    ParkingPlac(const ParkingPlac &p)
    {
        strncpy(adresa, p.adresa, 20);
        id=new char[strlen(p.id)+1];
        strcpy(id, p.id);
        cena=p.cena;
        n=p.n;
        for(int i=0; i<n; i++)
        {
            koli[i]=p.koli[i];
        }
    }
    ParkingPlac &operator=(const ParkingPlac &p)
    {
        if(this!=&p)
        {
            strncpy(adresa, p.adresa, 20);
            id=new char[strlen(p.id)+1];
            strcpy(id, p.id);
            cena=p.cena;
            n=p.n;
            for(int i=0; i<n; i++)
            {
                koli[i]=p.koli[i];
            }
        }
        return *this;
    }
    ~ParkingPlac()
    {
        delete[]id;
    }
    char *getId()
    {
        return id;
    }
    void pecati()
    {
        if(zarabotka==0)
        {
            cout<<id<<" "<<adresa<<endl;
        }
        else
        {
            cout<<id<<" "<<adresa<<" - "<<zarabotka<<" denari"<<endl;
        }
    }
    void platiCasovi(int casovi)
    {
        zarabotka+=casovi*cena;
    }
    bool daliIstaAdresa(ParkingPlac p)
    {
        if(!strcmp(p.adresa, adresa))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void parkirajVozilo(Avtomobil novoVozilo)
    {
        Avtomobil *tmp=new Avtomobil[n+1];
        for(int i=0; i<n; i++)
        {
            tmp[i]=koli[i];
        }
        delete[]koli;
        koli=tmp;
        tmp[n++]=novoVozilo;
    }
    void pecatiParkiraniVozila()
    {
        cout << "Vo parkingot se parkirani slednite vozila: " << endl;
        for(int i=0; i<n; i++)
        {
            cout <<i+1<<"."<<koli[i].getBoja()<<" "<<koli[i].getBrend()<<" "<<koli[i].getModel()<<endl;
        }
    }
};
int main(){

	ParkingPlac p[100];
	int n,m;
	char adresa[50],id[50];
	int brojcasovi,cenacas;
	cin>>n;
	if(n > 0){


		for (int i=0;i<n;i++){
	        cin.get();
			cin.getline(adresa,50);
			cin>>id>>cenacas;

			ParkingPlac edna(adresa,id,cenacas);

	        p[i]=edna;
		}

		//plakjanje
		cin>>m;
		for (int i=0;i<m;i++){

			cin>>id>>brojcasovi;

	        int findId=false;
	        for (int j=0;j<m;j++){
	            if (strcmp(p[j].getId(),id)==0){
	                p[j].platiCasovi(brojcasovi);
	                findId=true;
	            }
	        }
			if (!findId)
	        cout<<"Ne e platen parking. Greshen ID."<<endl;
		}

	    cout<<"========="<<endl;
	    ParkingPlac pCentar("Cvetan Dimov","C10",80);
		for (int i=0;i<n;i++)
	        if (p[i].daliIstaAdresa(pCentar))
	            p[i].pecati();
	} else {

		ParkingPlac najdobarPlac("Mars", "1337", 1);
	    int brVozila;
	    cin >> brVozila;
	    for(int i = 0; i < brVozila; ++i){

	    	char boja[20];
	    	char brend[20];
	    	char model[20];

	    	cin >> boja >> brend >> model;
	    	Avtomobil novAvtomobil(boja, brend, model);
	    	najdobarPlac.parkirajVozilo(novAvtomobil);
	    }
	    if(brVozila != 0)
	    najdobarPlac.pecatiParkiraniVozila();

	}
}
