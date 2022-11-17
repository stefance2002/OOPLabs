#include<iostream>
#include<cstring>
using namespace std;

class Busline
{
private:
    char poaganje[50];
    char pristiganje[50];
    int vremepoaganje;
    int vremepristiganje;
    float cena;
public:
    Busline(char*poaganje="", char*pristiganje="", int vremepoaganje=0, int vremepristiganje=0, float cena=0)
    {
        strcpy(this->poaganje, poaganje);
        strcpy(this->pristiganje, pristiganje);
        this->vremepoaganje=vremepoaganje;
        this->vremepristiganje=vremepristiganje;
        this->cena=cena;
    }
    Busline(const Busline &b)
    {
        strcpy(poaganje, b.poaganje);
        strcpy(pristiganje, b.pristiganje);
        vremepoaganje=b.vremepoaganje;
        vremepristiganje=b.vremepristiganje;
        cena=b.cena;
    }
    Busline&operator=(const Busline&b)
    {
        if(this!=&b)
        {
            strcpy(poaganje, b.poaganje);
            strcpy(pristiganje, b.pristiganje);
            vremepoaganje=b.vremepoaganje;
            vremepristiganje=b.vremepristiganje;
            cena=b.cena;
        }
        return *this;
    }
    ~Busline()
    {

    }
     char *getDepartureCity()
     {
         return poaganje;
     }
     char *getArrivalCity()
     {
         return pristiganje;
     }
     double duration()
     {
         int cas=(vremepristiganje/100)-(vremepoaganje/100);
         int minuti=(vremepristiganje%100)-(vremepoaganje%100);
         double d=cas+float(minuti)/60;
         return d;
     }
     void printBusline()
     {
         cout<<poaganje<<" -> "<<duration()<<" -> "
         <<pristiganje<<": "<<cena<<"EUR"<<endl;
     }
     bool istise(Busline b)
     {
         if(strcmp(poaganje, b.poaganje)==0 && strcmp(pristiganje, b.pristiganje)==0)
         {
             return true;
         }
         return false;
     }
friend class BusOperator;
};

class BusOperator
{
private:
    char ime[50];
    Busline *linii;
    int n;
public:
    BusOperator(char *ime="", Busline *linii=NULL, int n=0)
    {
        strcpy(this->ime, ime);
        this->linii=new Busline[n+1];
        for(int i=0; i<n; i++)
        {
            this->linii[i]=linii[i];
        }
        this->n=n;
    }
    BusOperator(const BusOperator&b)
    {
        strcpy(ime, b.ime);
        linii=new Busline[b.n+1];
        for(int i=0; i<n; i++)
        {
            linii[i]=b.linii[i];
        }
        n=b.n;
    }
    BusOperator&operator=(const BusOperator&b)
    {
        if(this!=&b)
        {
            delete[]linii;
            strcpy(ime, b.ime);
            linii=new Busline[b.n+1];
            for(int i=0; i<n; i++)
            {
                linii[i]=b.linii[i];
            }
            n=b.n;
        }
        return *this;
    }
    ~BusOperator()
    {
        delete[]linii;
    }
    void addBusline(Busline b)
    {
        int flag=1;
        for(int i=0; i<n; i++)
        {
            if(linii[i].istise(b))
            {
                flag=0;
            }
        }
        if(flag)
        {
            Busline *tmp=new Busline[n+1];
            for(int i=0; i<n; i++)
            {
                tmp[i]=linii[i];
            }
            tmp[n++]=b;
            delete[]linii;
            linii=tmp;
        }
    }
    int getN()
    {
        return n;
    }
     Busline getBus(int n)
    {
        return linii[n].printBusline();
    }
};
void searchBuslines(BusOperator b, char departureCity[], char arrivalCity[])
{
    for(int i=0; i<b.getN(); i++)
    {
        if(strcmp(b.linii[i].poaganje, departureCity)==0 &&strcmp(b.linii[i].pristiganje, arrivalCity)==0)
        {
            b.linii[i].printBusline();
        }
    }
}

//NE menuvaj nisto vo main funkcijata
int main(){

    int testCase;
    cin >> testCase;

    if(testCase == 1){
        cout << "====Testing class Busline constructors and additional methods====" << endl;
        Busline f1;
        char dep[50], arr[50];
        int dt, at;
        double pr;
        cin >> dep >> arr >> dt >> at >> pr;
        Busline f2(dep, arr, dt, at, pr);
        cout << f2.getDepartureCity() << " " << f2.getArrivalCity() << endl;
        cout << "Testing OK" << endl;
    }
    else if(testCase == 2){
        cout << "====Testing class Busline methods duration() and printBusline()====" << endl;
        char dep[50], arr[50];
        int dt, at;
        double pr;
        cin >> dep >> arr >> dt >> at >> pr;
        Busline f2(dep, arr, dt, at, pr);
        f2.printBusline();
        cout << endl;
    }
    else if(testCase == 3){
        cout << "====Testing class BusOperator constructors and methods====" << endl;
        BusOperator a("Strumica Ekspres");
        char dep[50], arr[50];
        int dt, at;
        double pr;
        cin >> dep >> arr >> dt >> at >> pr;
        Busline f1(dep, arr, dt, at, pr);
        a.addBusline(f1);
        Busline f3 = f1;
        a.addBusline(f3);
        a.getBus(0);
        cout << a.getN() << endl;
        BusOperator b = a;
        b.getBus(0);
        cin >> dep >> arr >> dt >> at >> pr;
        Busline f2(dep, arr, dt, at, pr);
        b.addBusline(f2);
        b.getBus(1);
        cout << "Testing OK" << endl;
    }
    else if(testCase == 4){
        cout << "====Testing global function====" << endl;
        BusOperator a("Strumica Ekspres");
        char dep[50], arr[50];
        double pr;
        int at, dt, n;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> dep >> arr >> dt >> at >> pr;
            Busline f(dep, arr, dt, at, pr);
            a.addBusline(f);
        }
        cin >> dep >> arr;
        searchBuslines(a, dep, arr);
        cout << endl << "Testing OK" << endl;
    }

    return 0;
}
