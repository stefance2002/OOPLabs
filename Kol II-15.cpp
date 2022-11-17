#include<iostream>
#include<string.h>
using namespace std;

class BadInputException
{
public:
    void poraka()
    {
        cout << "Greshna opisna ocenka" << endl;
    }
};

class StudentKurs{
   protected:
       char ime[30];
       int ocenka;
       bool daliUsno;
       static int MAX;

   public:
    StudentKurs(char* ime,int finalenIspit){
       strcpy(this->ime,ime);
       this->ocenka=finalenIspit;
       this->daliUsno=false;
     }
     static void setMAX(int m)
     {
         MAX=m;
     }
     bool getDaliUsno()
     {
         return daliUsno;
     }
     virtual int Ocenka()
    {
        return ocenka;
    }
     char* getIme()
    {
        return ime;
    }
    friend ostream &operator<<(ostream &o, StudentKurs &s)
    {
        o << s.ime << " --- ";
        if(s.Ocenka() > MAX)
        {
            o << MAX;
        }
        else
        {
            o << s.Ocenka();
        }
        o << endl;
        return o;
    }
};


class StudentKursUsno : public StudentKurs
{
private:
    char *opisnaUsno;
public:
    StudentKursUsno(char* ime,int finalenIspit):StudentKurs(ime, finalenIspit)
    {
        opisnaUsno=new char[0];
        daliUsno=true;
    }
     StudentKursUsno &operator+=(char *oo)
    {
        for(int i = 0; i < strlen(oo); i++)
        {
            if(!isalpha(oo[i]))
            {
                throw BadInputException();
            }
        }
        delete [] opisnaUsno;
        opisnaUsno = new char[strlen(oo) + 1];
        strcpy(opisnaUsno, oo);
        return *this;
    }
     int Ocenka()
    {
        if(!strcmp(opisnaUsno, "odlicen"))
        {
            return ocenka + 2;
        }
        else if(!strcmp(opisnaUsno, "dobro"))
        {
            return ocenka + 1;
        }
        else if(!strcmp(opisnaUsno, "losho"))
        {
            return ocenka - 1;
        }
        return ocenka;
    }
};


class KursFakultet{
private:
    char naziv[30];
    StudentKurs *studenti[20];
    int broj;
    static const int MINOCENKA = 6;

public:
    KursFakultet(char *naziv, StudentKurs** studenti,int broj ){
      strcpy(this->naziv,naziv);
      for (int i=0;i<broj;i++){
        //ako studentot ima usno isprashuvanje
        if (studenti[i]->getDaliUsno()){
            this->studenti[i]=new StudentKursUsno(*dynamic_cast<StudentKursUsno*>(studenti[i]));
        }
        else this->studenti[i]=new StudentKurs(*studenti[i]);
      }
      this->broj=broj;
    }
    ~KursFakultet(){
    for (int i=0;i<broj;i++) delete studenti[i];
    }
    void pecatiStudenti()
    {
        cout << "Kursot " << naziv << " go polozile:" << endl;
        for(int i = 0; i < broj; i++)
        {
            if(studenti[i]->Ocenka() >= MINOCENKA)
            {
                cout << *studenti[i];
            }
        }
    }

     void postaviOpisnaOcenka(char *im, char *oo)
    {
        for(int i = 0; i < broj; i++)
        {
            if(!strcmp(studenti[i]->getIme(), im))
            {
                StudentKursUsno *temp = dynamic_cast<StudentKursUsno*>(studenti[i]);
                if(temp)
                {
                    *temp += oo;
                }
            }
        }
    }
};

char* iscistiOcenka(char *o)
{
    int j = 0;
    char *temp = new char[strlen(o) + 1];
    for(int i = 0; i < strlen(o); i++)
    {
        if(isalpha(o[i]))
        {
            temp[j] = o[i];
            j++;
        }
    }
    temp[j] = '\0';
    return temp;
}

int StudentKurs::MAX=10;
int main(){

StudentKurs **niza;
int n,m,ocenka;
char ime[30],opisna[10];
bool daliUsno;
cin>>n;
niza=new StudentKurs*[n];
for (int i=0;i<n;i++){
   cin>>ime;
   cin>>ocenka;
   cin>>daliUsno;
   if (!daliUsno)
    niza[i]=new StudentKurs(ime,ocenka);
   else
    niza[i]=new StudentKursUsno(ime,ocenka);
}

KursFakultet programiranje("OOP",niza,n);
for (int i=0;i<n;i++) delete niza[i];
delete [] niza;
cin>>m;

for (int i=0;i<m;i++){
   cin>>ime>>opisna;
   try
        {
            programiranje.postaviOpisnaOcenka(ime,opisna);
        }
        catch(BadInputException &e)
        {
            e.poraka();
            programiranje.postaviOpisnaOcenka(ime, iscistiOcenka(opisna));
        }
}

StudentKurs::setMAX(9);

programiranje.pecatiStudenti();

}
