#include<iostream>
#include<cstring>
using namespace std;

class Kvadrat {
    protected:
    //TODO da se deklariraat promenlivite
    double a;
    public:
    //TODO default konstruktor
    Kvadrat(double n=0)
    {
        a=n;
    }
    //TODO copy konstruktor
    Kvadrat(const Kvadrat&k)
    {
        a=k.a;
    }
    //TODO double perimentar() {}
    double perimetar()
    {
        return 4*a;
    }
    //TODO double plostina() {}
    double plostina()
    {
        return a*a;
    }
    //TODO void pecati();
    void pecati()
    {
        cout<<"Kvadrat so dolzina a="<<a<<" ima plostina P="<<
        plostina()<<" i perimetar L="<<perimetar()<<endl;
    }
};

class Pravoagolnik : public Kvadrat
{ //da se vmetni nasleduvanjeto
    private:
    //deklariranje na promenlivite
    double x, y;
    public:
    //TODO default konstruktor
    Pravoagolnik():Kvadrat()
    {
        x=0;
        y=0;
    }
    Pravoagolnik(const Kvadrat &k, double x=0, double y=0):Kvadrat(k)
    {
        this->x=x;
        this->y=y;
    }
    Pravoagolnik(const Pravoagolnik &p):Kvadrat(p)
    {
        x=p.x;
        y=p.y;
    }
    double plostina()
    {
        return (a+x)*(a+y);
    }
    double perimetar()
    {
        return 2*(a+x)+2*(a+y);
    }
    void pecati()
    {
        if(x==y)
        {
            Kvadrat(a+x).pecati();
        }
        else
        {
            cout<< "Pravoagolnik so strani: "<<a+x<<" i "
            <<a+y<<" ima plostina P="<<plostina()<<
             " i perimetar L="<<perimetar()<<endl;
        }
    }
};

int main() {
	int n;
    double a,x,y;
	Kvadrat * kvadrati;
	Pravoagolnik * pravoagolnici;

	cin>>n;

    kvadrati = new Kvadrat [n];
    pravoagolnici = new Pravoagolnik [n];

	for (int i=0;i<n;i++){
		cin>>a;

		kvadrati[i] = Kvadrat(a);
	}

	for (int i=0;i<n;i++){
		cin>>x>>y;

		pravoagolnici[i]=Pravoagolnik(kvadrati[i],x,y);
	}

	int testCase;
	cin>>testCase;

	if (testCase==1){
		cout<<"===Testiranje na klasata Kvadrat==="<<endl;
		for (int i=0;i<n;i++)
			kvadrati[i].pecati();
	}
	else {
		cout<<"===Testiranje na klasata Pravoagolnik==="<<endl;
		for (int i=0;i<n;i++)
			pravoagolnici[i].pecati();
	}
}
