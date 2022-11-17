#include<iostream>
#include<cstring>
using namespace std;

class Person
{
private:
    char ime[20], prezime[20];
public:
    Person()
    {
        strncpy(ime, "not specified", 20);
        strncpy(prezime, "not specified", 20);
    }
    Person(char *i, char*p)
    {
        strcpy(ime, i);
        strcpy(prezime, p);
    }
    void print()
    {
        cout<<ime<<" "<<prezime<<endl;
    }
};

class Date
{
private:
    int year, month, day;
public:
    Date()
    {
        year=1;
        month=1;
        day=1;
    }
    Date(int y, int m, int d)
    {
        year=y;
        month=m;
        day=d;
    }
    void print()
    {
        cout<<year<<"."<<month<<"."<<day<<endl;
    }

};

class Car
{
private:
    Person owner;
    Date date;
    float price;
public:
    Car()
    {

    }
    Car(Person p, Date d, float price1)
    {
        owner=p;
        date=d;
        price=price1;
    }
    void print()
    {
        owner.print();
        date.print();
        cout<<"Price: "<<price;
    }
    float getPrice()
    {
        return price;
    }

};
void cheaperthan(Car c[], int n, float p)
    {
        for(int i=0; i<n; i++)
        {
            if(c[i].getPrice()<p)
            {
                c[i].print();
            }
        }
    }

int main() {
	char name[20];
	char lastName[20];
	int year;
	int month;
	int day;
	float price;

	int testCase;
	cin >> testCase;

	if (testCase == 1) {
		cin >> name;
		cin >> lastName;
		Person lik(name, lastName);

		cin >> year;
		cin >> month;
		cin >> day;
		Date date(year, month, day);

		cin >> price;
		Car car(lik, date,  price);

		car.print();
	}
	else if (testCase == 2) {
		cin >> name;
		cin >> lastName;
		Person lik(name, lastName);

		cin >> year;
		cin >> month;
		cin >> day;
		Date date(Date(year, month, day));

		cin >> price;
		Car car(lik, date,  price);
		car.print();
	}
	else {
		int numCars;
		cin >> numCars;

		Car cars[10];
		for (int i = 0; i < numCars; i++) {
			cin >> name;
			cin >> lastName;
			Person lik(name, lastName);

			cin >> year;
			cin >> month;
			cin >> day;
			Date date(year, month, day);

			cin >> price;
			cars[i] = Car(lik, date,  price);
		}
        float priceLimit;
        cin >> priceLimit;
		cheaperthan(cars, numCars, priceLimit);
	}


	return 0;
}
