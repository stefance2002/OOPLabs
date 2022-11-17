#include<iostream>
#include<cstring>
using namespace std;

class Exception
{
public:
    void poraka()
    {
        cout<<"Ne moze da se vnese dadeniot trud"<<endl;
    }
};

class Trud
{
private:
    char vid;
    int godina;
public:
    Trud(const char v='0', int g=0)
    {
        vid=v;;
        godina=g;
    }
    Trud(const Trud&d)
    {
        vid=d.vid;;
        godina=d.godina;
    }
    Trud&operator=(const Trud&d)
    {
        if(this!=&d)
        {
            vid=d.vid;;
            godina=d.godina;
        }
        return *this;
    }
    char getVid()const
    {
        return vid;
    }
    int getGodina()const
    {
        return godina;
    }
    friend istream &operator>>(istream &i, Trud &t)
    {
        return i>>t.vid>>t.godina;
    }
};

class Student
{
protected:
    char ime[30];
    int indeks, upis, n;
    int *oceni;
public:
    Student(const char *i="", int ind=0, int up=0, int *o=0, int nn=0)
    {
      strcpy(ime, i);
      indeks=ind;
      upis=up;
      n=nn;
      oceni=new int[n];
      for(int i=0; i<n; i++)
      {
          oceni[i]=o[i];
      }
    }
    virtual double rang()
    {
        double a=0;
        for(int i=0; i<n; i++)
        {
            a+=oceni[i];
        }
        return a/n;
    }
    friend ostream &operator<<(ostream &out, Student&s)
    {
        out<<s.indeks<<" "<<s.ime<<" "<<s.upis<<" "<<s.rang()<<endl;
    }
};

class PhDStudent : public Student
{
private:
    Trud *trudovi;
    int n;
    static int konferenciski;
    static int spisanie;
public:
    PhDStudent(const char *i="", int ind=0, int up=0, int *o=0, int nn=0, Trud *tr=0, int broj=0):Student(i,ind,up,o,nn)
    {
        n=broj;
        trudovi=new Trud[n+1];
        for(int i=0; i<n; i++)
        {
            trudovi[i]=tr[i];
        }
    }
    double rang()
    {
        double a=Student::rang();
        for(int i=0; i<n; i++)
        {
            if(tolower(trudovi[i].getVid()) == 'c')
            {
                a+=konferenciski;
            }
            else
            {
                a+=spisanie;
            }
        }
        return a;
    }
    PhDStudent&operator+=(const Trud&d)
    {
        if(d.getGodina()>=upis)
        {
            Trud *temp=new Trud[n+1];
            for(int i=0; i<n; i++)
            {
                temp[i]=trudovi[i];
            }
            delete[]trudovi;
            temp[n++]=d;
            trudovi=temp;
            return *this;
        }
        throw Exception();
    }
    static void setKonf(int conf)
    {
        konferenciski=conf;
    }
    static void setSpis(int conf)
    {
        spisanie=conf;
    }
};

int PhDStudent::konferenciski=1;
int PhDStudent::spisanie=3;

int main(){
	int testCase;
	cin >> testCase;

	int god, indeks, n, god_tr, m, n_tr;
	int izbor; //0 za Student, 1 za PhDStudent
	char ime[30];
	int oceni[50];
	char tip;
	Trud trud[50];

	if (testCase == 1){
		cout << "===== Testiranje na klasite ======" << endl;
		cin >> ime;
		cin >> indeks;
		cin >> god;
		cin >> n;
		for (int j = 0; j < n; j++)
			cin >> oceni[j];
		Student s(ime, indeks, god, oceni, n);
		cout << s;

		cin >> ime;
		cin >> indeks;
		cin >> god;
		cin >> n;
		for (int j = 0; j < n; j++)
			cin >> oceni[j];
		cin >> n_tr;
		for (int j = 0; j < n_tr; j++){
			cin >> tip;
			cin >> god_tr;
			Trud t(tip, god_tr);
			trud[j] = t;
		}
		PhDStudent phd(ime, indeks, god, oceni, n, trud, n_tr);
		cout << phd;
	}
	if (testCase == 2){
		cout << "===== Testiranje na operatorot += ======" << endl;
		Student **niza;
		cin >> m;
		niza = new Student *[m];
		for (int i = 0; i<m; i++){
			cin >> izbor;
			cin >> ime;
			cin >> indeks;
			cin >> god;
			cin >> n;
			for (int j = 0; j < n; j++)
				cin >> oceni[j];

			if (izbor == 0){
				niza[i] = new Student(ime, indeks, god, oceni, n);
			}
			else{
				cin >> n_tr;
				for (int j = 0; j < n_tr; j++){
					cin >> tip;
					cin >> god_tr;
					Trud t(tip, god_tr);
					trud[j] = t;
				}
				niza[i] = new PhDStudent(ime, indeks, god, oceni, n, trud, n_tr);
			}
		}
		// pecatenje na site studenti
		cout << "\nLista na site studenti:\n";
		for (int i = 0; i < m; i++)
			cout << *niza[i];

		// dodavanje nov trud za PhD student spored indeks
		Trud t;
		cin >> indeks;
		cin >> t;

		// vmetnete go kodot za dodavanje nov trud so pomos na operatorot +=

		// pecatenje na site studenti
		cout << "\nLista na site studenti:\n";
		for (int i = 0; i < m; i++)
			cout << *niza[i];
	}
	if (testCase == 3){
		cout << "===== Testiranje na operatorot += ======" << endl;
		Student **niza;
		cin >> m;
		niza = new Student *[m];
		for (int i = 0; i<m; i++){
			cin >> izbor;
			cin >> ime;
			cin >> indeks;
			cin >> god;
			cin >> n;
			for (int j = 0; j < n; j++)
				cin >> oceni[j];

			if (izbor == 0){
				niza[i] = new Student(ime, indeks, god, oceni, n);
			}
			else{
				cin >> n_tr;
				for (int j = 0; j < n_tr; j++){
					cin >> tip;
					cin >> god_tr;
					Trud t(tip, god_tr);
					trud[j] = t;
				}
				niza[i] = new PhDStudent(ime, indeks, god, oceni, n, trud, n_tr);
			}
		}
		// pecatenje na site studenti
		cout << "\nLista na site studenti:\n";
		for (int i = 0; i < m; i++)
			cout << *niza[i];

		// dodavanje nov trud za PhD student spored indeks
		Trud t;
		cin >> indeks;
		cin >> t;

		// vmetnete go kodot za dodavanje nov trud so pomos na operatorot += od Testcase 2


		// pecatenje na site studenti
		cout << "\nLista na site studenti:\n";
		for (int i = 0; i < m; i++)
			cout << *niza[i];
	}
	if (testCase == 4){
		cout << "===== Testiranje na isklucoci ======" << endl;
		cin >> ime;
		cin >> indeks;
		cin >> god;
		cin >> n;
		for (int j = 0; j < n; j++)
			cin >> oceni[j];
		cin >> n_tr;
		for (int j = 0; j < n_tr; j++){
			cin >> tip;
			cin >> god_tr;
			Trud t(tip, god_tr);
			trud[j] = t;
		}
		PhDStudent phd(ime, indeks, god, oceni, n, trud, n_tr);
		cout << phd;
	}
	if (testCase == 5){
		cout << "===== Testiranje na isklucoci ======" << endl;
		Student **niza;
		cin >> m;
		niza = new Student *[m];
		for (int i = 0; i<m; i++){
			cin >> izbor;
			cin >> ime;
			cin >> indeks;
			cin >> god;
			cin >> n;
			for (int j = 0; j < n; j++)
				cin >> oceni[j];

			if (izbor == 0){
				niza[i] = new Student(ime, indeks, god, oceni, n);
			}
			else{
				cin >> n_tr;
				for (int j = 0; j < n_tr; j++){
					cin >> tip;
					cin >> god_tr;
					Trud t(tip, god_tr);
					trud[j] = t;
				}
				niza[i] = new PhDStudent(ime, indeks, god, oceni, n, trud, n_tr);
			}
		}
		// pecatenje na site studenti
		cout << "\nLista na site studenti:\n";
		for (int i = 0; i < m; i++)
			cout << *niza[i];

		// dodavanje nov trud za PhD student spored indeks
		Trud t;
		cin >> indeks;
		cin >> t;

		// vmetnete go kodot za dodavanje nov trud so pomos na operatorot += i spravete se so isklucokot

		// pecatenje na site studenti
		cout << "\nLista na site studenti:\n";
		for (int i = 0; i < m; i++)
			cout << *niza[i];
	}
	if (testCase == 6){
		cout << "===== Testiranje na static clenovi ======" << endl;
		Student **niza;
		cin >> m;
		niza = new Student *[m];
		for (int i = 0; i<m; i++){
			cin >> izbor;
			cin >> ime;
			cin >> indeks;
			cin >> god;
			cin >> n;
			for (int j = 0; j < n; j++)
				cin >> oceni[j];

			if (izbor == 0){
				niza[i] = new Student(ime, indeks, god, oceni, n);
			}
			else{
				cin >> n_tr;
				for (int j = 0; j < n_tr; j++){
					cin >> tip;
					cin >> god_tr;
					Trud t(tip, god_tr);
					trud[j] = t;
				}
				niza[i] = new PhDStudent(ime, indeks, god, oceni, n, trud, n_tr);
			}
		}
		// pecatenje na site studenti
		cout << "\nLista na site studenti:\n";
		for (int i = 0; i < m; i++)
			cout << *niza[i];

		int conf, journal;
		cin >> conf;
		cin >> journal;

        //postavete gi soodvetnite vrednosti za statickite promenlivi
        PhDStudent::setKonf(conf);
        PhDStudent::setSpis(journal);
		// pecatenje na site studenti
		cout << "\nLista na site studenti:\n";
		for (int i = 0; i < m; i++)
			cout << *niza[i];
	}

	return 0;
}
