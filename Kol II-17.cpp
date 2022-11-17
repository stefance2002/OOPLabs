#include <iostream>
#include <cstring>
using namespace std;

class FudbalskaEkipa
{
protected:
    char trener[100];
    int golovi[10];
public:
    FudbalskaEkipa(const char*t="", int*g=0)
    {
        strcpy(trener, t);
        for(int i=0; i<10; i++)
        {
            golovi[i]=g[i];
        }
    }
    virtual char *getIme()=0;
    virtual int uspeh()=0;
    friend ostream&operator<<(ostream&out, FudbalskaEkipa &k)
    {
        out<<k.getIme()<<endl;
        out<<k.trener<<endl;
        out<<k.uspeh()<<endl;
        return out;
    }
    FudbalskaEkipa&operator+=(int n)
    {
        for(int i=0; i<9; i++)
        {
            golovi[i]=golovi[i+1];
        }
        golovi[9]=n;
    }
    int sumaGolovi()
    {
        int sum=0;
        for(int i=0; i<10; i++)
        {
            sum+=golovi[i];
        }
        return sum;
    }
};

class Klub : public FudbalskaEkipa
{
private:
    char ime[50];
    int tituli;
public:
    Klub(const char*t="", int*g=0, const char*i="", int tit=0):FudbalskaEkipa(t, g)
    {
        strcpy(ime, i);
        tituli=tit;
    }
    char *getIme()
    {
        return ime;
    }
    int uspeh()
    {
        return sumaGolovi()*3+tituli*1000;
    }
};

class Reprezentacija : public FudbalskaEkipa
{
private:
    char ime[50];
    int nastapi;
public:
    Reprezentacija(const char*t="", int*g=0, const char*i="", int tit=0):FudbalskaEkipa(t, g)
    {
        strcpy(ime, i);
        nastapi=tit;
    }
    char *getIme()
    {
        return ime;
    }
    int uspeh()
    {
        return sumaGolovi()*3+nastapi*50;
    }
};

void najdobarTrener(FudbalskaEkipa **f, int n)
{
    int maxI=0;
    for(int i=0; i<n; i++)
    {
        if(f[i]->uspeh()>f[maxI]->uspeh())
        {
            maxI=i;
        }
    }
    cout<<f[maxI];
}

int main() {
    int n;
    cin >> n;
    FudbalskaEkipa **ekipi = new FudbalskaEkipa*[n];
    char coach[100];
    int goals[10];
    char x[100];
    int tg;
    for (int i = 0; i < n; ++i) {
        int type;
        cin >> type;
        cin.getline(coach, 100);
        cin.getline(coach, 100);
        for (int j = 0; j < 10; ++j) {
            cin >> goals[j];
        }
        cin.getline(x, 100);
        cin.getline(x, 100);
        cin >> tg;
        if (type == 0) {
            ekipi[i] = new Klub(coach, goals, x, tg);
        } else if (type == 1) {
            ekipi[i] = new Reprezentacija(coach, goals, x, tg);
        }
    }
    cout << "===== SITE EKIPI =====" << endl;
    for (int i = 0; i < n; ++i) {
        cout << *ekipi[i];
    }
    cout << "===== DODADI GOLOVI =====" << endl;
    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        cout << "dodavam golovi: " << p << endl;
        *ekipi[i] += p;
    }
    cout << "===== SITE EKIPI =====" << endl;
    for (int i = 0; i < n; ++i) {
        cout << *ekipi[i];
    }
    cout << "===== NAJDOBAR TRENER =====" << endl;
    najdobarTrener(ekipi, n);
    for (int i = 0; i < n; ++i) {
        delete ekipi[i];
    }
    delete [] ekipi;
    return 0;
}
