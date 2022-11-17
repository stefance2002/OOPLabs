#include <iostream>
#include <cstring>

using namespace std;

class Potpisuvac
{
private:
    char ime[20], prezime[20], embg[14];
public:
    Potpisuvac()
    {

    }
    Potpisuvac(char *i, char *p, char *e)
    {
        strcpy(ime, i);
        strcpy(prezime, p);
        strcpy(embg, e);
    }
    char *getembg()
    {
        return embg;
    }
};
class Dogovor
{
private:
    int broj;
    char kategorija[50];
    Potpisuvac p[3];
public:
    Dogovor()
    {

    }
    Dogovor(int n, char *k, Potpisuvac pp[])
    {
        broj=n;
        strcpy(kategorija, k);
        p[0]=pp[0];
        p[1]=pp[1];
        p[2]=pp[2];
    }
    bool proverka()
    {
        if(strcmp(p[0].getembg(), p[1].getembg())==0)
        {
            return 1;
        }
        if(strcmp(p[0].getembg(), p[2].getembg())==0)
        {
            return 1;
        }
        if(strcmp(p[2].getembg(), p[1].getembg())==0)
        {
            return 1;
        }
        return 0;
    }
};

int main()
{
    char embg[14], ime[20], prezime[20], kategorija[50];
    int broj, n;
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> embg >> ime >> prezime;
    	Potpisuvac p1(ime, prezime, embg);
    	cin >> embg >> ime >> prezime;
    	Potpisuvac p2(ime, prezime, embg);
    	cin >> embg >> ime >> prezime;
    	Potpisuvac p3(ime, prezime, embg);
    	cin >> broj >> kategorija;
    	Potpisuvac p[3];
    	p[0] = p1; p[1] = p2; p[2] = p3;
    	Dogovor d(broj, kategorija, p);
        cout << "Dogovor " << broj << ":" << endl;
    	if(d.proverka() == true)
    	    cout << "Postojat potpishuvaci so ist EMBG" << endl;
    	else
    	    cout << "Ne postojat potpishuvaci so ist EMBG" << endl;
    }
    return 0;
}
