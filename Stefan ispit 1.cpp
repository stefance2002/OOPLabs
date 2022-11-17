#include <cstring>
#include <iostream>
using namespace std;

class InvalidOperation
{
public:
    void pecati()
    {
        cout<<"Can’t merge two different cryptocurrencies."<<endl;
    }
};

class Cryptocurrency
{
private:
    char *ime, kod[7];
    double cena, kolicina;
    static double provizija;
public:
    Cryptocurrency(const char*i="", const char *k="", double c=0, double kol=0)
    {
        ime=new char[strlen(i)+1];
        strcpy(ime, i);
        strcpy(kod, k);
        cena=c;
        kolicina=kol;
    }
    Cryptocurrency(const Cryptocurrency &c)
    {
        ime=new char[strlen(c.ime)+1];
        strcpy(ime, c.ime);
        strcpy(kod, c.kod);
        cena=c.cena;
        kolicina=c.kolicina;
    }
    Cryptocurrency&operator=(const Cryptocurrency&c)
    {
        if(this!=&c)
        {
            delete[]ime;
            ime=new char[strlen(c.ime)+1];
            strcpy(ime, c.ime);
            strcpy(kod, c.kod);
            cena=c.cena;
            kolicina=c.kolicina;
        }
        return *this;
    }
    friend ostream &operator<<(ostream&out, const Cryptocurrency&c)
    {
        out<<c.kod<<" "<<c.ime<<" "<<c.cena<<" "<<c.kolicina<<
        " "<<c.cena*c.kolicina<<endl;
        return out;
    }
    Cryptocurrency&operator+=(Cryptocurrency&c)
    {
        if(strcmp(ime, c.ime) && strcmp(kod, c.kod))
        {
            throw InvalidOperation();
        }
        else
        {
            cena=c.cena;
            kolicina+=c.kolicina;
        }
        return *this;
    }
    double sell()
    {
        double a=cena*kolicina;
        kolicina=0;
        return a-(a*provizija/100);
    }
    static double setProvision(double f)
    {
        provizija=f;
    }
    char *getKod()
    {
        return kod;
    }
    char *getIme()
    {
        return ime;
    }
};

class Wallet
{
private:
    char sopstvenik[40];
    Cryptocurrency *valuti;
    int n;
public:
    Wallet(const char *i="")
    {
        strcpy(sopstvenik, i);
        n=0;
        valuti=new Cryptocurrency[0];
    }
    Wallet(const Wallet&w)
    {
        strcpy(sopstvenik, w.sopstvenik);
        n=w.n;
        valuti=new Cryptocurrency[n];
        for(int i=0; i<n; i++)
        {
            valuti[i]=w.valuti[i];
        }
    }
    Wallet&operator=(const Wallet&w)
    {
        if(this!=&w)
        {
            delete[]valuti;
            strcpy(sopstvenik, w.sopstvenik);
            n=w.n;
            valuti=new Cryptocurrency[n];
            for(int i=0; i<n; i++)
            {
                valuti[i]=w.valuti[i];
            }
        }
        return *this;
    }
    friend ostream &operator<<(ostream&out, const Wallet&c)
    {
        out<<c.sopstvenik<<endl;
        out<<"Cryptocurrencies:"<<endl;
        if(c.n==0)
        {
            out<<"EMPTY"<<endl;
            return out;
        }
        for(int i=0; i<c.n; i++)
        {
            out<<c.valuti[i];
        }
        return out;
    }
    Wallet&operator+=(Cryptocurrency &c)
    {
        int flag=1;
        for(int i=0; i<n; i++)
        {
            if(!strcmp(valuti[i].getIme(), c.getIme())&&!strcmp(valuti[i].getKod(), c.getKod()))
            {
                valuti[i]+=c;
                flag=0;
            }
        }
        if(flag)
        {
            Cryptocurrency *tmp=new Cryptocurrency[n+1];
            for(int i=0; i<n; i++)
            {
                tmp[i]=valuti[i];
            }
            tmp[n++]=c;
            delete[]valuti;
            valuti=tmp;
        }
    }
};

double Cryptocurrency::provizija=2.5;

int main() {
    int testCase;
    cin >> testCase;

    if (testCase == 0) {
        cout << "Cryptocurrency constructors" << endl;
        Cryptocurrency c1("Cardano", "ADA", 1.45);
        Cryptocurrency c2("Cardano", "ADA", 1.45, 2.5);
        cout << "TEST PASSED" << endl;
    } else if (testCase == 1) {
        cout << "Cryptocurrency copy-constructor and operator =" << endl;
        Cryptocurrency c2("Cardano", "ADA", 1.45, 2.5);
        Cryptocurrency c1 = c2; //copy-constructor
        Cryptocurrency c3("BITCOIN", "BTC", 35000, 0.0001);
        c3 = c2;
        cout << "TEST PASSED" << endl;
    } else if (testCase == 2) {
        cout << "Cryptocurrency operator <<" << endl;
        Cryptocurrency c1("Cardano", "ADA", 1.45);
        Cryptocurrency c2("Cardano", "ADA", 1.45, 2.5);
        cout << c1;
        cout << c2;
    } else if (testCase == 3) {
        cout << "Cryptocurrency operator += (normal behavior)" << endl;
        Cryptocurrency c1("Cardano", "ADA", 1.45, 8);
        Cryptocurrency c2("Cardano", "ADA", 1.39, 2.5);
        cout<<c1<<"+="<<endl<<c2<<"-->"<<endl;

        try
        {
            cout <<(c1+=c2);
        }
        catch(InvalidOperation&o)
        {
            o.pecati();
        };
    } else if (testCase == 4) {
        cout << "Cryptocurrency operator += (abnormal behavior)" << endl;
        Cryptocurrency c1("Cardano", "ADA", 1.45, 8);
        Cryptocurrency c2("Bitcoin", "BTC", 35000, 0.0008);
        cout<<c1<<"+="<<endl<<c2<<"-->"<<endl;
        try
        {
            cout <<(c1+=c2);
        }
        catch(InvalidOperation&o)
        {
            o.pecati();
        };

    } else if (testCase == 5) {
        cout << "Cryptocurrency method sell and static members test" << endl;
        int n;
        cin >> n;
        Cryptocurrency *cryptocurrencies1 = new Cryptocurrency[n];
        Cryptocurrency *cryptocurrencies2 = new Cryptocurrency[n];
        char name[50], code[7];
        double price, quantity;
        for (int i = 0; i < n; i++) {
            cin >> name >> code >> price >> quantity;
            cryptocurrencies1[i] = Cryptocurrency(name, code, price, quantity);
            cryptocurrencies2[i] = Cryptocurrency(name, code, price, quantity);
        }
        cout << "BEFORE CHANGE OF PROVISION PERCENT" << endl;
        for (int i = 0; i < n; i++) {
            cout << "    BEFORE SELLING --> " << cryptocurrencies1[i];
            cout << "     PROFIT FROM SELLING -->" << cryptocurrencies1[i].sell() << endl;
            cout << "    AFTER SELLING --> " << cryptocurrencies1[i];
        }
        Cryptocurrency::setProvision(5.1);
        cout << "AFTER CHANGE OF PROVISION PERCENT" << endl;
        for (int i = 0; i < n; i++) {
            cout << "    BEFORE SELLING --> " << cryptocurrencies2[i];
            cout << "     PROFIT FROM SELLING -->" << cryptocurrencies2[i].sell() << endl;
            cout << "    AFTER SELLING --> " << cryptocurrencies2[i];
        }

        delete[] cryptocurrencies1;
        delete[] cryptocurrencies2;
    } else if (testCase == 6) {
        cout << "Wallet constructors" << endl;
        Wallet w1("John Doe");
        Wallet w2("John Doe");
        cout << "TEST PASSED" << endl;
    } else if (testCase == 7) {
        cout << "Wallet copy-constructor and operator =" << endl;
        Wallet w1("John Doe");
        Wallet w2("John Doe");
        Wallet w3 = w1; //copy constructor;
        w2 = w1; //operator =
        cout << "TEST PASSED" << endl;
    } else if (testCase == 8) {
        cout << "Wallet operator <<" << endl;
        Wallet w1("John Doe");
        cout << w1;
    } else if (testCase == 9) {
        cout << "Wallet += and <<" << endl;
        Wallet wallet("John Doe");
        int n;
        cin >> n;
        char name[50], code[7];
        double price, quantity;
        for (int i = 0; i < n; i++) {
            cin >> name >> code >> price >> quantity;
            Cryptocurrency c(name, code, price, quantity);
            wallet += c;
        }
        cout << wallet;
    }
    return 0;
}


