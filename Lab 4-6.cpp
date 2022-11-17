#include<iostream>
#include<cstring>
using namespace std;

enum Tip{Linux, Unix, Windows};
class OperativenSistem
{
private:
    char *ime;
    float verzija;
    Tip tipovi;
    float golemina;
public:
    OperativenSistem()
    {
        ime=new char[0];
        verzija=0;
        tipovi=(Tip)0;
        golemina=0;
    }
    OperativenSistem(char *ime, float verzija, Tip tipovi, float golemina)
    {
        this->ime=new char[strlen(ime)+1];
        strcpy(this->ime, ime);
        this->verzija=verzija;
        this->tipovi=tipovi;
        this->golemina=golemina;
    }
    OperativenSistem(const OperativenSistem &sistem)
    {
        ime=new char[strlen(sistem.ime)+1];
        strcpy(ime, sistem.ime);
        verzija=sistem.verzija;
        tipovi=sistem.tipovi;
        golemina=sistem.golemina;
    }
    OperativenSistem &operator =(const OperativenSistem &sistem)
    {
        if(this!=&sistem)
        {
            delete []ime;

            ime=new char[strlen(sistem.ime)+1];
            strcpy(ime, sistem.ime);
            verzija=sistem.verzija;
            tipovi=sistem.tipovi;
            golemina=sistem.golemina;
        }
        return *this;
    }
    ~OperativenSistem()
    {
        delete []ime;
    }
    void pecati()
    {
        cout<<"Ime: "<<ime<<" Verzija: "<<verzija
        <<" Tip: "<<tipovi<<" Golemina:"<<golemina<<"GB"<<endl;
    }
    bool ednakviSe(const OperativenSistem &os)
    {
        if(strcmp(ime,os.ime)==0 && verzija==os.verzija
        && tipovi==os.tipovi && golemina==os.golemina)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int sporediVerzija(const OperativenSistem &os)
    {
        if(verzija==os.verzija)
        {
            return 0;
        }
        else if(verzija<os.verzija)
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }
    bool istaFamilija(const OperativenSistem &sporedba)
    {
         if(strcmp(ime,sporedba.ime)==0 && tipovi==sporedba.tipovi)
         {
             return true;
         }
         else
         {
             return false;
         }
    }
    friend class Repozitorium;
};

class Repozitorium
{
private:
    char ime[20];
    OperativenSistem *sistemi;
    int broj;
public:
    Repozitorium(const char *ime)
    {
        strcpy(this->ime, ime);
        sistemi=new OperativenSistem[0];
        broj=0;
    }
    ~Repozitorium()
    {
        delete []sistemi;
    }
    void pecatiOperativniSistemi()
    {
        cout<<"Repozitorium: "<<ime<<endl;
        for(int i=0; i<broj; i++)
        {
            sistemi[i].pecati();
        }
    }
    void izbrishi(const OperativenSistem &operativenSistem)
    {
        for(int i = 0; i < broj; i++)
        {
            if(sistemi[i].ednakviSe(operativenSistem))
            {
                for(int j = i; j < broj - 1; j++)
                {
                    sistemi[j] = sistemi[j+1];
                }
                broj--;
                i++;
            }
        }
    }

    void dodadi(const OperativenSistem &nov)
    {
        for(int i = 0; i < broj; i++)
        {
            if(sistemi[i].istaFamilija(nov) && sistemi[i].sporediVerzija(nov) == -1)
            {
                sistemi[i] = nov;
                return;
            }
        }

        OperativenSistem *temp = new OperativenSistem[broj + 1];
        for(int i = 0; i < broj; i++)
        {
            temp[i] = sistemi[i];
        }
        delete [] sistemi;
        sistemi = temp;
        sistemi[broj++] = nov;
    }
};

int main() {
    char repoName[20];
    cin>>repoName;
    Repozitorium repozitorium=Repozitorium(repoName);
    int brojOperativniSistemi = 0;
    cin>>brojOperativniSistemi;
    char ime[20];
    float verzija;
    int tip;
    float golemina;
    for (int i = 0; i<brojOperativniSistemi; i++){
        cin>>ime;
        cin>>verzija;
        cin>>tip;
        cin>>golemina;
        OperativenSistem os = OperativenSistem(ime, verzija, (Tip)tip, golemina);
        repozitorium.dodadi(os);
    }

    repozitorium.pecatiOperativniSistemi();
     cin>>ime;
    cin>>verzija;
    cin>>tip;
    cin>>golemina;
    OperativenSistem os = OperativenSistem(ime, verzija, (Tip)tip, golemina);
    cout<<"=====Brishenje na operativen sistem====="<<endl;
    repozitorium.izbrishi(os);
    repozitorium.pecatiOperativniSistemi();
    return 0;
}
