#include<iostream>
#include<cstring>
using namespace std;

class Ekipa
{
protected:
    char ime[15];
    int pobedi;
    int porazi;
public:
    Ekipa(char *ime="", int pobedi=0, int porazi=0)
    {
        strcpy(this->ime, ime);
        this->pobedi=pobedi;
        this->porazi=porazi;
    }
    Ekipa(const Ekipa &e)
    {
        strcpy(this->ime, e.ime);
        this->pobedi=e.pobedi;
        this->porazi=e.porazi;
    }
    void pecati()
    {
        cout<<"Ime: "<<ime<<" Pobedi: "<<pobedi<<" Porazi: "<<porazi;
    }
};

class FudbalskaEkipa : public Ekipa
{
private:
    int crveni, zolti, nereseni;
public:
    FudbalskaEkipa(char *i="", int pb=0, int p=0, int c=0, int z=0, int n=0) : Ekipa(i, pb, p)
    {
        strcpy(this->ime, i);
        this->pobedi=pb;
        this->porazi=p;
        crveni=c;
        zolti=z;
        nereseni=n;
    }
    int poeni()
    {
        return (pobedi*3+nereseni);
    }
    void pecati()
    {
        Ekipa::pecati();
        cout<<" Nereseni: "<<nereseni<<" Poeni: "<<poeni()<<endl;
    }
};

int main(){
	char ime[15];
	int pob,por,ck,zk,ner;
	cin>>ime>>pob>>por>>ck>>zk>>ner;
	FudbalskaEkipa f1(ime,pob,por,ck,zk,ner);
	f1.pecati();
	return 0;
}
