#include <iostream>
#include <string.h>
using namespace std;

class PlDrustvo
{
private:
    char *ime;
    int brTuri;
    int brClenovi;
public:
    PlDrustvo(char *ime="", int turi=0, int n=0)
    {
        this->ime=new char[strlen(ime)+1];
        strcpy(this->ime, ime);
        brClenovi=n;
        brTuri=turi;
    }
    PlDrustvo(const PlDrustvo &p)
    {
        ime=new char[strlen(p.ime)+1];
        strcpy(ime, p.ime);
        brClenovi=p.brClenovi;
        brTuri=p.brTuri;
    }
    PlDrustvo &operator=(const PlDrustvo &p)
    {
        if(this!=&p)
        {
            ime=new char[strlen(p.ime)+1];
            strcpy(ime, p.ime);
            brClenovi=p.brClenovi;
            brTuri=p.brTuri;
        }
        return *this;
    }
    PlDrustvo operator+(const PlDrustvo &p)
    {
        if(brClenovi>p.brClenovi)
        {
            PlDrustvo p1(ime, brTuri, brClenovi+p.brClenovi);
            return p1;
        }
        else
        {
            PlDrustvo p1(p.ime, p.brTuri, brClenovi+p.brClenovi);
            return p1;
        }
    }
    bool operator>(const PlDrustvo &pd)
    {
        if(brClenovi > pd.brClenovi)
        {
            return  true;
        }
        else return false;
    }

    bool operator<(const PlDrustvo &pd)
    {
        return !(*this > pd);
    }

    friend ostream &operator<<(ostream &o, const PlDrustvo &pd)
    {
        return o << "Ime: " << pd.ime << " Turi: " << pd.brTuri << " Clenovi: " << pd.brClenovi << endl;
    }

    int getClenovi()
    {
        return brClenovi;
    }
};
void najmnoguClenovi(PlDrustvo *pd, int n)
    {
        int maks = 0;
        for(int i = 0; i < n; i++)
        {
            if(pd[i].getClenovi() > pd[maks].getClenovi())
            {
                maks = i;
            }
        }
        cout << "Najmnogu clenovi ima planinarskoto drustvo: " << pd[maks];
        }

int main()
{
    PlDrustvo drustva[3];
    PlDrustvo pl;
    for (int i=0;i<3;i++)
   	{
    	char ime[100];
    	int brTuri;
    	int brClenovi;
    	cin>>ime;
    	cin>>brTuri;
    	cin>>brClenovi;
    	PlDrustvo p(ime,brTuri,brClenovi);
        drustva[i] = p;

   	}

    pl = drustva[0] + drustva[1];
    cout<<pl;

    najmnoguClenovi(drustva, 3);

    return 0;
}
