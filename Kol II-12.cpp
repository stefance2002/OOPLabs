#include <iostream>
#include <cstring>
using namespace std;

enum Tip{smartfon, kompjuter};

class InvalidProductionDate
{
public:
    void pecati()
    {
        cout<<"Невалидна година на производство"<<endl;
    }
};

class Device
{
private:
    char model[100];
    Tip tip;
    static float proverka;
    int godina;
public:
    Device(const char *m="", Tip t=(Tip)0, int g=0)
    {
        strcpy(model, m);
        tip=t;
        godina=g;
    }
    Device(const Device&d)
    {
        strcpy(model, d.model);
        tip=d.tip;
        proverka=d.proverka;
        godina=d.godina;
    }
    Device&operator=(const Device &d)
    {
        if(this!=&d)
        {
            strcpy(model, d.model);
            tip=d.tip;
            proverka=d.proverka;
            godina=d.godina;
        }
        return *this;
    }
    static void setPocetniCasovi(float d)
    {
        proverka=d;
    }
    friend ostream &operator<<(ostream&out, Device&d)
    {
        float dodatok=0;
        out<<d.model<<endl;
        if(d.godina>2015)
        {
            dodatok+=2;
        }
        if(d.tip==1)
        {
            dodatok+=2;
            out<<"Laptop "<<proverka+dodatok<<endl;
        }
        else
        {
            out<<"Mobilen "<<proverka+dodatok<<endl;
        }
        return out;
    }
    int getGodina()const
    {
        return godina;
    }
};

class MobileServis
{
private:
    char adresa[100];
    Device *uredi;
    int n;
public:
    MobileServis(const char *a="")
    {
        strcpy(adresa, a);
        uredi=new Device[0];
        n=0;
    }
    MobileServis(const MobileServis&m)
    {
        strcpy(adresa, m.adresa);
        uredi=new Device[m.n];
        n=m.n;
        for(int i=0; i<n; i++)
        {
            uredi[i]=m.uredi[i];
        }
    }
    MobileServis&operator=(const MobileServis&m)
    {
        if(this!=&m)
        {
            delete[]uredi;
            strcpy(adresa, m.adresa);
            uredi=new Device[m.n];
            n=m.n;
            for(int i=0; i<n; i++)
            {
                uredi[i]=m.uredi[i];
            }
        }
        return *this;
    }
    MobileServis&operator+=(const Device&d)
    {
        if(d.getGodina()>2019 || d.getGodina()<2000)
        {
            throw InvalidProductionDate();
        }
        Device *temp=new Device[n+1];
        for(int i=0; i<n; i++)
        {
            temp[i]=uredi[i];
        }
        temp[n++]=d;
        delete[]uredi;
        uredi=temp;
        return *this;
    }
    void pecatiCasovi()
    {
        cout<<"Ime: "<<adresa<<endl;
        for(int i=0; i<n; i++)
        {
            cout<<uredi[i];
        }
    }
};

float Device::proverka=1;

int main()
{
	int testCase;
	cin >> testCase;
    char ime[100];
    int tipDevice;
    int godina;
    int n;
    Device devices[50];
	if (testCase == 1){
		cout << "===== Testiranje na klasite ======" << endl;
		cin >> ime;
		cin >> tipDevice;
		cin >> godina;
		Device ig(ime,(Tip)tipDevice,godina);
        cin>>ime;
		MobileServis t(ime);
        cout<<ig;
		}
	if (testCase == 2){
		cout << "===== Testiranje na operatorot += ======" << endl;
        cin>>ime;
        cin >> n;
		MobileServis t(ime);
		for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(Tip)tipDevice,godina);
            try
            {
                t+=tmp;
            }
            catch(InvalidProductionDate&d)
            {
                d.pecati();
            }
        }
        t.pecatiCasovi();
	}
	if (testCase == 3){
		cout << "===== Testiranje na isklucoci ======" << endl;
        cin>>ime;
        cin >> n;
		MobileServis t(ime);
		for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(Tip)tipDevice,godina);
            try
            {
                t+=tmp;
            }
            catch(InvalidProductionDate&d)
            {
                d.pecati();
            }
        }
        t.pecatiCasovi();
	}
	if (testCase == 4){
		cout <<"===== Testiranje na konstruktori ======"<<endl;
        cin>>ime;
        cin >> n;
		MobileServis t(ime);
		for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(Tip)tipDevice,godina);
            try
            {
                t+=tmp;
            }
            catch(InvalidProductionDate&d)
            {
                d.pecati();
            }
        }
        MobileServis t2 = t;
        t2.pecatiCasovi();
	}
	if (testCase == 5){
		cout << "===== Testiranje na static clenovi ======" << endl;
        cin>>ime;
        cin >> n;
		MobileServis t(ime);
		for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(Tip)tipDevice,godina);

            try
            {
                t+=tmp;
            }
            catch(InvalidProductionDate&d)
            {
                d.pecati();
            }
        }
        t.pecatiCasovi();
        cout << "===== Promena na static clenovi ======" << endl;
		Device::setPocetniCasovi(2);
        t.pecatiCasovi();
	}
		if (testCase == 6){
		cout << "===== Testiranje na kompletna funkcionalnost ======" << endl;
		cin>>ime;
        cin >> n;
		MobileServis t(ime);
		for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(Tip)tipDevice,godina);
            try
            {
                t+=tmp;
            }
            catch(InvalidProductionDate&d)
            {
                d.pecati();
            }
        }
		Device::setPocetniCasovi(3);
        MobileServis t2 = t;
        t2.pecatiCasovi();
	}
	return 0;
}
