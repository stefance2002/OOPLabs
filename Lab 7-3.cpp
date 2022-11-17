#include <iostream>
#include <cmath>
using namespace std;
//TODO: konstruiraj ja abstraknata klasa Shape
class Shape
{
protected:
    int a;
public:
    Shape(int aa=0)
    {
        a=aa;
    }
    virtual double plostina()=0;
    virtual void pecati()=0;
    virtual int getType()=0;
};
//TODO: konstruiraj ja klasata Kvadrat
class Square : public Shape
{
public:
    Square(int aa) : Shape(aa)
    {

    }
    double plostina()
    {
        return a*a;
    }
    void pecati()
    {
        cout<<"Kvadrat so plostina = "<<plostina()<<endl;
    }
    int getType()
    {
        return 1;
    }
};
//TODO: konstruiraj ja klasata Krug
class Circle : public Shape
{
public:
    Circle(int aa) : Shape(aa)
    {

    }
    double plostina()
    {
        return a*a*3.14;
    }
    void pecati()
    {
        cout<<"Krug so plostina = "<<plostina()<<endl;
    }
    int getType()
    {
        return 2;
    }
};
//TODO: konstruiraj ja klasata Triagolnik
class Triangle : public Shape
{
public:
    Triangle(int aa) : Shape(aa)
    {

    }
    double plostina()
    {
        return (sqrt(3)/4)*a*a;
    }
    void pecati()
    {
        cout<<"Triagolnik so plostina = "<<plostina()<<endl;
    }
    int getType()
    {
        return 3;
    }
};
void checkNumTypes(Shape** niza, int n)
{
    int s=0, c=0, t=0;
    for(int i=0; i<n; i++)
    {
        if(niza[i]->getType()==1)
        {
            s++;
        }
        else if(niza[i]->getType()==2)
        {
            c++;
        }
        else
        {
            t++;
        }
    }
    cout<<"Broj na kvadrati vo nizata = "<<s<<endl;
    cout<<"Broj na krugovi vo nizata = "<<c<<endl;
    cout<<"Broj na triagolnici vo nizata = "<<t<<endl;
}

int main(){
	int n;
	cin >> n;
	//TODO: inicijaliziraj niza od pokazuvachi kon klasata Shape
    Shape **niza;
    niza=new Shape*[n];
	int classType;
	int side;
	//TODO: konstruiraj for ciklus so chija pomosh ke ja popolnish nizata
	for(int i = 0; i < n; ++i)
    {
		cin >> classType;
		cin >> side;
        if(classType==1)
        {
            niza[i]=new Square(side);
        }
        else if(classType==2)
        {
            niza[i]=new Circle(side);
        }
        else
        {
            niza[i]=new Triangle(side);
        }
	}
	for(int i = 0; i < n; ++i)
    {
		niza[i]->pecati();
	}
	checkNumTypes(niza, n);
	return 0;
}
