#include<iostream>
#include<string.h>
using namespace std;

class Koncert
{
private:
    char ime[20], lokacija[20];
    static double popust;
    double price;
public:
    Koncert(const char *i="", const char*l="", float p=0)
    {
        strcpy(ime, i);
        strcpy(lokacija, l);
        price=p;
    }
    virtual double cena()const
    {
        return price-price*popust;
    }
    char*getNaziv()
    {
        return ime;
    }
    static double getSezonskiPopust()
    {
        return popust;
    }
    double getPrice()
    {
        return price;
    }
    static double setSezonskiPopust(double p)
    {
        popust=p;
    }
};

class ElektronskiKoncert:public Koncert
{
private:
    char *dj;
    double traenje;
    bool dnevna;
public:
    ElektronskiKoncert(const char *i="", const char*l="", float p=0, const char *d="", double t=0, bool nok=false):Koncert(i, l, p)
    {
        dj=new char[strlen(d)+1];
        strcpy(dj, d);
        traenje=t;
        dnevna=nok;
    }
    double cena()const
    {
        double a=Koncert::cena();
        if(traenje>7)
        {
            a+=360;
        }
        else if(traenje>5)
        {
            a+=150;
        }
        if(dnevna)
        {
            a-=50;
        }
        else
        {
            a+=100;
        }
        return a;
    }
};

void najskapKoncert(Koncert ** koncerti, int n)
{
    int maxI=0, el=0;
    for(int i=0; i<n; i++)
    {
        if(koncerti[i]->cena()>koncerti[maxI]->cena())
        {
            maxI=i;
        }
        ElektronskiKoncert *temp=dynamic_cast<ElektronskiKoncert*>(koncerti[i]);
        if(temp)
        {
            el++;
        }
    }
    cout<<"Najskap koncert: "<<koncerti[maxI]->getNaziv()<<" "<<koncerti[maxI]->cena()<<endl;
    cout<<"Elektronski koncerti: "<<el<<" od vkupno "<<n<<endl;
}

bool prebarajKoncert(Koncert ** koncerti, int n, char * naziv, bool elektronski)
{
    bool flag=false;
    for(int i=0; i<n; i++)
    {
        if(elektronski)
        {
            ElektronskiKoncert *temp=dynamic_cast<ElektronskiKoncert*>(koncerti[i]);
            if(temp && !strcmp(naziv, koncerti[i]->getNaziv()))
            {
                cout<<naziv<<" "<<koncerti[i]->cena()<<endl;
                flag=true;
            }
        }
        else
        {
            if(!strcmp(naziv, koncerti[i]->getNaziv()))
            {
                cout<<naziv<<" "<<koncerti[i]->cena()<<endl;
                flag=true;
            }
        }
    }
    return flag;
}

double Koncert::popust=0.2;

int main(){

    int tip,n,novaCena;
    char naziv[100], lokacija[100], imeDJ[40];
    bool dnevna;
    float cenaBilet, novPopust;
    float casovi;

        cin>>tip;
        if (tip==1){//Koncert
        	cin>>naziv>>lokacija>>cenaBilet;
        	Koncert k1(naziv,lokacija,cenaBilet);
        	cout<<"Kreiran e koncert so naziv: "<<k1.getNaziv()<<endl;
        }
        else if (tip==2){//cena - Koncert
            cin>>naziv>>lokacija>>cenaBilet;
        	Koncert k1(naziv,lokacija,cenaBilet);
        	cout<<"Osnovna cena na koncertot so naziv "<<k1.getNaziv()<< " e: " <<k1.cena()<<endl;
        }
        else if (tip==3){//ElektronskiKoncert
            cin>>naziv>>lokacija>>cenaBilet>>imeDJ>>casovi>>dnevna;
            ElektronskiKoncert s(naziv,lokacija,cenaBilet,imeDJ,casovi,dnevna);
            cout<<"Kreiran e elektronski koncert so naziv "<<s.getNaziv()<<" i sezonskiPopust "<<s.getSezonskiPopust()<<endl;
        }
        else if (tip==4){//cena - ElektronskiKoncert
             cin>>naziv>>lokacija>>cenaBilet>>imeDJ>>casovi>>dnevna;
             ElektronskiKoncert s(naziv,lokacija,cenaBilet,imeDJ,casovi,dnevna);
             cout<<"Cenata na elektronskiot koncert so naziv "<<s.getNaziv()<<" e: "<<s.cena()<<endl;
        }
        else if (tip==5) {//najskapKoncert

        }
        else if (tip==6) {//prebarajKoncert
            Koncert ** koncerti = new Koncert *[5];
            int n;
            koncerti[0] = new Koncert("Area","BorisTrajkovski",350);
            koncerti[1] = new ElektronskiKoncert("TomorrowLand","Belgium",8000,"Afrojack",7.5,false);
            koncerti[2] = new ElektronskiKoncert("SeaDance","Budva",9100,"Tiesto",5,true);
            koncerti[3] = new Koncert("Superhiks","PlatoUkim",100);
            koncerti[4] = new ElektronskiKoncert("CavoParadiso","Mykonos",8800,"Guetta",3,true);
            char naziv[100];
        	najskapKoncert(koncerti,5);
        }
        else if (tip==7){//prebaraj
        	  Koncert ** koncerti = new Koncert *[5];
            int n;
            koncerti[0] = new Koncert("Area","BorisTrajkovski",350);
            koncerti[1] = new ElektronskiKoncert("TomorrowLand","Belgium",8000,"Afrojack",7.5,false);
            koncerti[2] = new ElektronskiKoncert("SeaDance","Budva",9100,"Tiesto",5,true);
            koncerti[3] = new Koncert("Superhiks","PlatoUkim",100);
            koncerti[4] = new ElektronskiKoncert("CavoParadiso","Mykonos",8800,"Guetta",3,true);
            char naziv[100];
            bool elektronski;
        	cin>>elektronski;
        	if(prebarajKoncert(koncerti,5, "Area",elektronski))
                cout<<"Pronajden"<<endl;
            else cout<<"Ne e pronajden"<<endl;

            if(prebarajKoncert(koncerti,5, "Area",!elektronski))
                cout<<"Pronajden"<<endl;
            else cout<<"Ne e pronajden"<<endl;

        }
        else if (tip==8){//smeni cena
        	  Koncert ** koncerti = new Koncert *[5];
            int n;
            koncerti[0] = new Koncert("Area","BorisTrajkovski",350);
            koncerti[1] = new ElektronskiKoncert("TomorrowLand","Belgium",8000,"Afrojack",7.5,false);
            koncerti[2] = new ElektronskiKoncert("SeaDance","Budva",9100,"Tiesto",5,true);
            koncerti[3] = new Koncert("Superhiks","PlatoUkim",100);
            koncerti[2] -> setSezonskiPopust(0.9);
        	najskapKoncert(koncerti,4);
        }

    return 0;
}
