#include<iostream>
#include<cstring>
using namespace std;

class Nedviznina
{
protected:
    char *ime;
    int kvad;
    int cenna;
public:
    Nedviznina(char *ime="", int kvad=0, int cenna=0)
    {
        this->ime=new char[strlen(ime)+1];
        strcpy(this->ime, ime);
        this->kvad=kvad;
        this->cenna=cenna;
    }
    Nedviznina(const Nedviznina &n)
    {
        this->ime=new char[strlen(n.ime)+1];
        strcpy(this->ime, n.ime);
        this->kvad=n.kvad;
        this->cenna=n.cenna;
    }
    friend istream &operator>>(istream &in, Nedviznina &n)
    {
        in>>n.ime>>n.kvad>>n.cenna;
        return in;
    }
    int cena()
    {
        return  kvad*cenna;
    }
    void pecati()
    {
        cout<<ime<<", "<<"Kvadratura: "<<kvad
        <<", "<<"Cena po Kvadrat: " <<cenna;
    }
    float danokNaImot()
    {
        return (float)cena()*0.05;
    }
    char *getAdresa()
    {
        return ime;
    }
};

class Vila : public Nedviznina
{
private:
    int danok;
public:
    Vila():Nedviznina()
    {
        danok=0;
    }
    void pecati()
    {
        Nedviznina::pecati();
        cout<<", Danok na luksuz: "<<danok<<endl;
    }
    friend istream &operator>>(istream &in, Vila &v)
    {
        in>>v.ime >> v.kvad >> v.cenna >> v.danok;
    }
    float danokNaImot()
    {
        return cena()*(0.05+danok/100.);
    }
};

int main(){
    Nedviznina n;
    Vila v;
    cin>>n;
    cin>>v;
    n.pecati();
    cout<<endl;
    cout<<"Danok za: "<<n.getAdresa()<<", e: "<<n.danokNaImot()<<endl;
    v.pecati();
    cout<<"Danok za: "<<v.getAdresa()<<", e: "<<v.danokNaImot()<<endl;
    return 0;
}
