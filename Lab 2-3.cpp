#include <iostream>
#include <cstring>
using namespace std;

class Film
{
private:
    char ime[100];
    char reziser[50];
    char genre[50];
    int godina;
public:
    Film()
    {
        strcpy(ime, "");
        strcpy(reziser, "");
        strcpy(genre, "");
        godina=1000;
    }
    Film(char *i, char *r, char *g, int god)
    {
        strcpy(ime, i);
        strcpy(reziser, r);
        strcpy(genre, g);
        godina=god;
    }
    void setime(char *i)
    {
        strcpy(ime, i);
    }
    void setreziser(char *r)
    {
        strcpy(reziser, r);
    }
    void setgenre(char *g)
    {
        strcpy(genre, g);
    }
    void setgodina(int god)
    {
        godina=god;
    }
    char getime()
    {
        return *ime;
    }
    char getreziser()
    {
        return *reziser;
    }
    char getgenre()
    {
        return *genre;
    }
    int getgodina()
    {
        return godina;
    }
    void print()
    {
        cout<<"Ime: "<<ime<<endl;
        cout<<"Reziser: "<<reziser<<endl;
        cout<<"Zanr: "<<genre<<endl;
        cout<<"Godina: "<<godina<<endl;
    }
};

void pecati(Film *f, int n, int godina)
{
    for(int i=0; i<n; i++)
    {
        if(f[i].getgodina()==godina)
        {
            f[i].print();
        }
    }
}

int main() {
 	int n;
 	cin >> n;
 	//da se inicijalizira niza od objekti od klasata Film
 	Film f[100];
 	for(int i = 0; i < n; ++i) {
 		char ime[100];
 		char reziser[50];
 		char zanr[50];
 		int godina;
 		cin >> ime;
 		cin >> reziser;
 		cin >> zanr;
 		cin >> godina;
 		//da se kreira soodveten objekt
 		f[i].setime(ime);
 		f[i].setreziser(reziser);
 		f[i].setgenre(zanr);
 		f[i].setgodina(godina);
 	}
 	int godina;
 	cin >> godina;
 	//da se povika funkcijata pecati_po_godina
 	pecati(f, n, godina);
 	return 0;
 }
