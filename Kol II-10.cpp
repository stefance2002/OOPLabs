#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

class NegativnaVrednost
{
public:
    void print()
    {
        cout<<"Oglasot ima nevalidna vrednost za cenata i nema da bide evidentiran!"<<endl;
    }
};

class Oglas
{
private:
    char naslov[50], kategorija[30], opis[100];
    double cena;
public:
    Oglas(const char *naslov2="", const char *kategorija2="", const char *opis2="", double cena2=0)
    {
        strcpy(naslov, naslov2);
        strcpy(kategorija, kategorija2);
        strcpy(opis, opis2);
        cena=cena2;
    }
    Oglas(Oglas &o)
    {
        strcpy(naslov, o.naslov);
        strcpy(kategorija, o.kategorija);
        strcpy(opis, o.opis);
        cena=o.cena;
    }
    Oglas&operator=(Oglas &o)
    {
        if(this!=&o)
        {
            strcpy(naslov, o.naslov);
            strcpy(kategorija, o.kategorija);
            strcpy(opis, o.opis);
            cena=o.cena;
        }
        return *this;
    }
    bool operator>(Oglas &o)
    {
        return cena>o.cena;
    }
    friend ostream &operator<<(ostream &out, Oglas &o)
    {
        out<<o.naslov<<endl;
        out<<o.opis<<endl;
        out<<o.cena<<" evra"<<endl;
        return out;
    }
    double getCena()
    {
        return cena;
    }
    char*getKategorija()
    {
        return kategorija;
    }
};

class Oglasnik
{
private:
    char ime[20];
    Oglas *oglasi;
    int n;
public:
    Oglasnik(const char *ime2="", Oglas *og=0, int n2=0)
    {
        strcpy(ime, ime2);
        n=n2;
        oglasi=new Oglas[n];
        for(int i=0; i<n; i++)
        {
            oglasi[i]=og[i];
        }
    }
    Oglasnik &operator+=(Oglas &o)
    {
        if(o.getCena()<0)
        {
            throw NegativnaVrednost();
        }
        else
        {
            Oglas *temp=new Oglas[n+1];
            for(int i=0; i<n; i++)
            {
                temp[i]=oglasi[i];
            }
            temp[n++]=o;
            delete[]oglasi;
            oglasi=temp;
            return *this;
        }
    }
    friend ostream&operator<<(ostream&out, Oglasnik &o)
    {
        out<<o.ime<<endl;
        for(int i=0; i<o.n; i++)
        {
            out<<o.oglasi[i]<<endl;
        }
    }
    void oglasiOdKategorija(const char *k)
    {
        for(int i=0; i<n; i++)
        {
            if(!strcmp(k, oglasi[i].getKategorija()))
            {
                cout<<oglasi[i]<<endl;
            }
        }
    }
    void najniskaCena()
    {
        int najmala=0;
        for(int i=0; i<n; i++)
        {
            if(najmala>oglasi[i].getCena())
            {
                najmala=i;
            }
        }
        cout<<oglasi[najmala];
    }
};

int main(){

    char naslov[50];
    char kategorija[30];
    char opis[100];
    float cena;
    char naziv[50];
    char k[30];
    int n;

    int tip;
    cin>>tip;

    if (tip==1){
        cout<<"-----Test Oglas & operator <<-----" <<endl;
        cin.get();
		cin.getline(naslov,49);
        cin.getline(kategorija,29);
        cin.getline(opis,99);
        cin>>cena;
        Oglas o(naslov, kategorija, opis, cena);
        cout<<o;
    }
    else if (tip==2){
    	cout<<"-----Test Oglas & operator > -----" <<endl;
        cin.get();
		cin.getline(naslov,49);
        cin.getline(kategorija,29);
        cin.getline(opis,99);
        cin>>cena;
        Oglas o1(naslov, kategorija, opis, cena);
        cin.get();
		cin.getline(naslov,49);
        cin.getline(kategorija,29);
        cin.getline(opis,99);
        cin>>cena;
        Oglas o2(naslov, kategorija, opis, cena);
        if (o1>o2) cout<<"Prviot oglas e poskap."<<endl;
        else cout<<"Prviot oglas ne e poskap."<<endl;
    }
    else if (tip==3){
        cout<<"-----Test Oglasnik, operator +=, operator << -----" <<endl ;
        cin.get();
		cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
        	Oglas o(naslov, kategorija, opis, cena);
            try
			{
                ogl+=o;
			}
			catch(NegativnaVrednost&n)
			{
			    n.print();
			}
        }
        cout<<ogl;
    }
    else if (tip==4){
      	cout<<"-----Test oglasOdKategorija -----" <<endl ;
      	cin.get();
		cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
        	Oglas o(naslov, kategorija, opis, cena);
            try
			{
                ogl+=o;
			}
			catch(NegativnaVrednost&n)
			{
			    n.print();
			}
        }
        cin.get();
		cin.getline(k,29);
        cout<<"Oglasi od kategorijata: " <<k<<endl;
      	ogl.oglasiOdKategorija(k);

    }
    else if (tip==5){
    	cout<<"-----Test Exception -----" <<endl ;
      	cin.get();
		cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
        	Oglas o(naslov, kategorija, opis, cena);
			try
			{
                ogl+=o;
			}
			catch(NegativnaVrednost&n)
			{
			    n.print();
			}
        }
        cout<<ogl;

    }
    else if (tip==6){
    	cout<<"-----Test najniskaCena -----" <<endl ;
      	cin.get();
		cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
        	Oglas o(naslov, kategorija, opis, cena);
            try
			{
                ogl+=o;
			}
			catch(NegativnaVrednost&n)
			{
			    n.print();
			}
        }
        cout<<"Oglas so najniska cena:"<<endl;
      	ogl.najniskaCena();

    }
    else if (tip==7){
    	cout<<"-----Test All -----" <<endl ;
      	cin.get();
		cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
        	Oglas o(naslov, kategorija, opis, cena);
            try
			{
                ogl+=o;
			}
			catch(NegativnaVrednost&n)
			{
			    n.print();
			}
        }
        cout<<ogl;

        cin.get();
        cin.get();
		cin.getline(k,29);
        cout<<"Oglasi od kategorijata: " <<k<<endl;
      	ogl.oglasiOdKategorija(k);

        cout<<"Oglas so najniska cena:"<<endl;
      	ogl.najniskaCena();

    }

	return 0;
}
