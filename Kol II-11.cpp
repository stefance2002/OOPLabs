#include<iostream>
#include<string.h>
using namespace std;

class Delo
{
private:
    char ime[50], zemja[50];
    int godina;
public:
    Delo(const char *i="", int g=0, const char *z="")
    {
        strcpy(ime, i);
        strcpy(zemja, z);
        godina=g;
    }
    Delo(const Delo &d)
    {
        strcpy(ime, d.ime);
        strcpy(zemja, d.zemja);
        godina=d.godina;
    }
    Delo&operator=(const Delo &d)
    {
        if(this!=&d)
        {
            strcpy(ime, d.ime);
            strcpy(zemja, d.zemja);
            godina=d.godina;
        }
        return *this;
    }
    bool operator==(const Delo &d)
    {
        return !strcmp(ime, d.ime);
    }
    const char*getZemja()
    {
        return zemja;
    }
    const char*getIme()
    {
        return ime;
    }
    int getGodina()
    {
        return godina;
    }
};

class Pretstava
{
protected:
    Delo d;
    int karti;
    char data[15];
public:
    Pretstava(Delo dd=0, int n=0, const char*i="")
    {
        d=dd;
        karti=n;
        strcpy(data, i);
    }
    virtual int cena()
    {
        int n=0, m=0;
        if(!strcmp(d.getZemja(), "Italija"))
        {
            n+=100;
        }
        else if(!strcmp(d.getZemja(), "Rusija"))
        {
            n+=150;
        }
        else
        {
            n+=80;
        }
        if(d.getGodina()>1899)
        {
            m+=50;
        }
        else if(d.getGodina()>1799)
        {
            m+=75;
        }
        else
        {
            m+=100;
        }
        return m+n;
    }
    Delo getDelo()
    {
        return d;
    }
    int getKarti()
    {
        return karti;
    }
};

class Balet : public Pretstava
{
private:
    static int dodatok;
public:
    Balet(Delo dd=0, int n=0, const char*i=""):Pretstava(dd, n, i)
    {

    }
    int cena()
    {
        return Pretstava::cena()+dodatok;
    }
    static int setCenaBalet(int n)
    {
        dodatok=n;
    }
};

class Opera : public Pretstava
{
public:
    Opera(Delo dd=0, int n=0, const char*i=""):Pretstava(dd, n, i)
    {

    }
    int cena()
    {
        return Pretstava::cena();
    }

};

int prihod(Pretstava **p, int n)
{
    int sum=0;
    for(int i=0; i<n; i++)
    {
        sum+=p[i]->cena()*p[i]->getKarti();
    }
    return sum;
}

int brojPretstaviNaDelo(Pretstava **p, int n, Delo d)
{
    int brojac=0;
    for(int i=0; i<n; i++)
    {
        if(p[i]->getDelo()==d)
        {
            brojac++;
        }
    }
    return brojac;
}
//citanje na delo
Delo readDelo(){
    char ime[50];
    int godina;
    char zemja[50];
    cin>>ime>>godina>>zemja;
    return Delo(ime,godina,zemja);
}
//citanje na pretstava
Pretstava* readPretstava(){
    int tip; //0 za Balet , 1 za Opera
    cin>>tip;
    Delo d=readDelo();
    int brojProdadeni;
    char data[15];
    cin>>brojProdadeni>>data;
    if (tip==0)  return new Balet(d,brojProdadeni,data);
    else return new Opera(d,brojProdadeni,data);
}

int Balet::dodatok=150;
int main(){
    int test_case;
    cin>>test_case;

    switch(test_case){
    case 1:
    //Testiranje na klasite Opera i Balet
    {
        cout<<"======TEST CASE 1======="<<endl;
        Pretstava* p1=readPretstava();
        cout<<p1->getDelo().getIme()<<endl;
        Pretstava* p2=readPretstava();
        cout<<p2->getDelo().getIme()<<endl;
    }break;

    case 2:
    //Testiranje na  klasite Opera i Balet so cena
    {
        cout<<"======TEST CASE 2======="<<endl;
        Pretstava* p1=readPretstava();
        cout<<p1->cena()<<endl;
        Pretstava* p2=readPretstava();
        cout<<p2->cena()<<endl;
    }break;

    case 3:
    //Testiranje na operator ==
    {
        cout<<"======TEST CASE 3======="<<endl;
        Delo f1=readDelo();
        Delo f2=readDelo();
        Delo f3=readDelo();

        if (f1==f2) cout<<"Isti se"<<endl; else cout<<"Ne se isti"<<endl;
        if (f1==f3) cout<<"Isti se"<<endl; else cout<<"Ne se isti"<<endl;

    }break;

    case 4:
    //testiranje na funkcijata prihod
    {
        cout<<"======TEST CASE 4======="<<endl;
        int n;
        cin>>n;
        Pretstava **pole=new Pretstava*[n];
        for (int i=0;i<n;i++){
            pole[i]=readPretstava();

        }
        cout<<prihod(pole,n);
    }break;

    case 5:
    //testiranje na prihod so izmena na cena za 3d proekcii
    {
        cout<<"======TEST CASE 5======="<<endl;
        int cenaBalet;
        cin>>cenaBalet;
        Balet::setCenaBalet(cenaBalet);
        int n;
        cin>>n;
        Pretstava **pole=new Pretstava*[n];
        for (int i=0;i<n;i++){
            pole[i]=readPretstava();
        }
        cout<<prihod(pole,n);
        }break;

    case 6:
    //testiranje na brojPretstaviNaDelo
    {
        cout<<"======TEST CASE 6======="<<endl;
        int n;
        cin>>n;
        Pretstava **pole=new Pretstava*[n];
        for (int i=0;i<n;i++){
            pole[i]=readPretstava();
        }

        Delo f=readDelo();
        cout<<brojPretstaviNaDelo(pole,n,f);
    }break;

    };


return 0;
}
