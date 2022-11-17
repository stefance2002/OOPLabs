#include <iostream>
#include <cstring>
using namespace std;

class Gitara
{
private:
    char seriski[25];
    double cena;
    int godina;
    char tip[40];
public:
    Gitara(char *tip="", char *seriski="", int godina=0, double cena=0)
    {
        strcpy(this->tip, tip);
        strcpy(this->seriski, seriski);
        this->cena=cena;
        this->godina=godina;
    }
    Gitara(const Gitara &g)
    {
        strcpy(this->tip, g.tip);
        strcpy(this->seriski, g.seriski);
        this->cena=cena;
        this->godina=godina;
    }
    Gitara &operator=(const Gitara &g)
    {
        strcpy(this->tip, g.tip);
        strcpy(this->seriski, g.seriski);
        this->cena=g.cena;
        this->godina=g.godina;
        return *this;
    }
    ~Gitara()
    {

    }
    bool daliIsti(Gitara &g)
    {
        return strcmp(this->seriski, g.seriski)==0;
    }
    void pecati()
    {
        cout<<seriski<<" "<<tip<<" "<<cena<<endl;
    }
    char *getTip()
    {
        return tip;
    }
    int getGodina()
    {
        return godina;
    }
    double getNabavna()
    {
        return cena;
    }
    char *getSeriski()
    {
        return seriski;
    }
    friend class Magacin;
};

class Magacin
{
private:
    char ime[30];
    char lokacija[60];
    Gitara *gitari;
    int n, otvoranje;
public:
    Magacin(char *ime="", char* lokacija="", int otvoranje=0)
    {
        strcpy(this->ime, ime);
        strcpy(this->lokacija, lokacija);
        this->otvoranje=otvoranje;
        n=0;
        gitari=NULL;
    }
    Magacin(const Magacin &m)
    {
        strcpy(this->ime, ime);
        strcpy(this->lokacija, lokacija);
        this->otvoranje=otvoranje;
        this->n=m.n;
        for(int i=0; i<n; i++)
        {
            gitari[i]=m.gitari[i];
        }
    }
    Magacin &operator=(const Magacin &m)
    {
        delete [] gitari;
            strcpy(this->lokacija,m.lokacija);
            strcpy(this->ime,m.ime);
            this->otvoranje = m.otvoranje;
            gitari = new Gitara[m.n];
            for(int i =0;i<m.n;i++)
                gitari[i] = m.gitari[i];
            n = m.n;
            return *this;
    }
    ~Magacin()
    {
        delete []gitari;
    }

    double vrednost()
    {
        double sum=0;
        for(int i=0; i<n; i++)
        {
            sum+=gitari[i].getNabavna();
        }
        return sum;
    }
    void dodadi(Gitara &g)
    {
        Gitara *tmp=new Gitara[n+1];
        for(int i=0; i<n; i++)
        {
            tmp[i]=gitari[i];
        }
        tmp[n++]=g;
        delete[]gitari;
        gitari=tmp;
    }
    void prodadi(Gitara g)
    {
        int newn=0;
        for(int i=0;i<n;i++)
            {
                if(gitari[i].daliIsti(g)==false)
                {
                    newn++;
                }
            }
        Gitara *tmp=new Gitara[newn];
        int j=0;
        for(int i=0; i<n; i++)
        {
            if(gitari[i].daliIsti(g)==false)
                {
                   tmp[j] = gitari[i];
                   j++;
                }
        }
        delete[]gitari;
        gitari=tmp;
        n=newn;
    }
    void pecati(bool b)
    {
        cout<<ime<<" "<<lokacija<<endl;
       for(int i=0;i<n;i++)
            {
                if(b==true&&gitari[i].getGodina()>otvoranje)
                {
                    gitari[i].pecati();
                }
                else if(b==false){
                   gitari[i].pecati();
                }
            }
    }
};

    int main() {
	// se testira zadacata modularno
    int testCase;
    cin >> testCase;

	int n, godina;
	float cena;
	char seriski[50],tip[50];

	if(testCase == 1) {
        cout << "===== Testiranje na klasata Gitara ======" << endl;
        cin>>tip;
        cin>>seriski;
        cin >> godina;
        cin >> cena;
        Gitara g(tip,seriski, godina,cena);
		cout<<g.getTip()<<endl;
		cout<<g.getSeriski()<<endl;
		cout<<g.getGodina()<<endl;
		cout<<g.getNabavna()<<endl;
    } else if(testCase == 2){
        cout << "===== Testiranje na klasata Magacin so metodot print() ======" << endl;
		Magacin kb("Magacin1","Lokacija1");
        kb.pecati(false);
	}
    else if(testCase == 3) {
        cout << "===== Testiranje na klasata Magacin so metodot dodadi() ======" << endl;
        Magacin kb("Magacin1","Lokacija1",2005);
		cin>>n;
			for (int i=0;i<n;i++){
                cin>>tip;
                cin>>seriski;
                cin >> godina;
                cin >> cena;
                Gitara g(tip,seriski, godina,cena);
                cout<<"gitara dodadi"<<endl;
				kb.dodadi(g);
			}
        kb.pecati(true);
    }

    else if(testCase == 4) {
        cout << "===== Testiranje na klasata Magacin so metodot prodadi() ======" << endl;
        Magacin kb("Magacin1","Lokacija1",2012);
            cin>>n;
            Gitara brisi;
			for (int i=0;i<n;i++){
                cin>>tip;
                cin>>seriski;
                cin >> godina;
                cin >> cena;

                Gitara g(tip,seriski, godina,cena);
                if(i==2)
                    brisi=g;
                cout<<"gitara dodadi"<<endl;
				kb.dodadi(g);
			}
        kb.pecati(false);
        kb.prodadi(brisi);
        kb.pecati(false);
    }
    else if(testCase == 5) {
        cout << "===== Testiranje na klasata Magacin so metodot prodadi() i pecati(true) ======" << endl;
        Magacin kb("Magacin1","Lokacija1",2011);
            cin>>n;
            Gitara brisi;
			for (int i=0;i<n;i++){
                cin>>tip;
                cin>>seriski;
                cin >> godina;
                cin >> cena;

                Gitara g(tip,seriski, godina,cena);
                if(i==2)
                    brisi=g;
                cout<<"gitara dodadi"<<endl;
				kb.dodadi(g);
			}
        kb.pecati(true);
        kb.prodadi(brisi);
        cout<<"Po brisenje:"<<endl;
        Magacin kb3;
        kb3=kb;
        kb3.pecati(true);
    }
   else if(testCase ==6)
        {
        cout << "===== Testiranje na klasata Magacin so metodot vrednost()======" << endl;
        Magacin kb("Magacin1","Lokacija1",2011);
            cin>>n;
            Gitara brisi;
			for (int i=0;i<n;i++){
                cin>>tip;
                cin>>seriski;
                cin >> godina;
                cin >> cena;

                Gitara g(tip,seriski, godina,cena);
                if(i==2)
                    brisi=g;
				kb.dodadi(g);
			}
        cout<<kb.vrednost()<<endl;
        kb.prodadi(brisi);
        cout<<"Po brisenje:"<<endl;
        cout<<kb.vrednost();
        Magacin kb3;
        kb3=kb;
        }
    return 0;
}
