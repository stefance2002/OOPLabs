#include<iostream>
using namespace std;

class Number {
    public:
    //TODO da se deklariraat trite cisto virtuelni metodi
    virtual double doubleValue()=0;
    virtual int intValue()=0;
    virtual void print()=0;
};

//ТODO preoptovaruvanje na operatorot ==
bool operator==(Number &n, Number&m)
{
    return (n.doubleValue() == m.doubleValue() && n.intValue() == m.intValue());
}

class Integer : public Number{ //TODO da se dodadi izraz za nasleduvanje od Number
    private:
    //TODO da se deklariraat promenlivite
    int a;
    public:
    //TODO konstruktor so eden argument
    Integer(int b)
    {
        a=b;
    }
    //TODO da se prepokrijat metodite od klasata Number
    double doubleValue()
    {
        return 0;
    }

    int intValue()
    {
        return a;
    }

    void print()
    {
        cout<<"Integer: "<<a<<endl;
    }
};

class Double : public Number{ //TODO da se dodadi izraz za nasleduvanje od Number
    private:
    //TODO da se deklariraat promenlivite
    double d;
    public:
    //TODO konstruktor so eden argument
    Double(double b)
    {
        d=b;
    }
    //TODO da se prepokrijat metodite od klasata Number
    double doubleValue()
    {
        return d-(int)d;
    }

    int intValue()
    {
        return (int)d;
    }

    void print()
    {
        cout<<"Double: "<<d<<endl;
    }
};

class Numbers{
    private:
    //TODO deklariranje na promenlivite
    Number **n;
    int br;
    public:
    //TODO default konstruktor
    Numbers()
    {
        n=new Number*[0];
        br=0;
    }
    ~Numbers()
    {
        delete[]*n;
    }
    //TODO operator += (operatorot da prima pointer od objekt od Number, a ne referenca)
    Numbers &operator+=(Number *nn)
    {
        Number **temp=new Number*[br+1];
        for(int i=0; i<br; i++)
        {
            if(*n[i]==*nn)
            {
                delete[]temp;
                return *this;
            }
            temp[i]=n[i];
        }
        delete[]n;
        n=temp;
        n[br++]=nn;
        return *this;
    }


    int countInt()
    {
        int sum = 0;
        for(int i = 0; i < br; i++)
        {
            if(n[i]->doubleValue() == 0)
            {
                sum++;
            }
        }
        return sum;
    }

    int sumInt()
    {
        int sum = 0;
        for(int i = 0; i < br; i++)
        {
            if(n[i]->doubleValue() == 0)
            {
                sum += n[i]->intValue();
            }
        }
        return sum;
    }

    int countDouble()
    {
        int sum = 0;
        for(int i = 0; i < br; i++)
        {
            if(n[i]->doubleValue() != 0)
            {
                sum++;
            }
        }
        return sum;
    }

    double sumDouble()
    {
        double sum = 0;
        for(int i = 0; i < br; i++)
        {
            if(n[i]->doubleValue() != 0)
            {
                sum += n[i]->intValue() + n[i]->doubleValue();
            }
        }
        return sum;
    }
    double sumOfAll()
    {
        return sumDouble()+sumInt();
    }
    //TODO void statistics()
    void statistics()
    {
        cout << "Count of numbers: " << br<< endl;
        cout << "Sum of all numbers: " << sumOfAll() << endl;
        cout << "Count of integer numbers: " << countInt() << endl;
        cout << "Sum of integer numbers: " << sumInt() << endl;
        cout << "Count of double numbers: " << countDouble() << endl;
        cout << "Sum of double numbers: " << sumDouble() << endl;
    }
    //TODO void integersLessThan (Integer n)
    void integersLessThan(Integer nn)
    {
        int c = 0;
        for(int i = 0; i < br; i++)
        {
            if(n[i]->intValue() < nn.intValue() && n[i]->doubleValue() == 0)
            {
                n[i]->print();
                c++;
            }
        }
        if(c == 0)
        {
            cout << "None" << endl;
        }
    }

    void doublesBiggerThan(Double nn)
    {
        int c = 0;
        for(int i = 0; i < br; i++)
        {
            if(n[i]->intValue() + n[i]->doubleValue() > nn.intValue() + nn.doubleValue() && n[i]->doubleValue() != 0)
            {
                n[i]->print();
                c++;
            }
        }
        if(c == 0)
        {
            cout << "None" << endl;
        }
    }
};

int main() {

	int n;
	cin>>n;
	Numbers numbers;
	for (int i=0;i<n;i++){
		int type;
		double number;
		cin>>type>>number;
		if (type==0){//Integer object
			Integer * integer = new Integer((int) number);
			numbers+=integer;
		}
		else {
			Double * doublee = new Double(number);
			numbers+=doublee;
		}
	}

	int lessThan;
	double biggerThan;

	cin>>lessThan;
	cin>>biggerThan;

	cout<<"STATISTICS FOR THE NUMBERS\n";
	numbers.statistics();
	cout<<"INTEGER NUMBERS LESS THAN "<<lessThan<<endl;
	numbers.integersLessThan(Integer(lessThan));
	cout<<"DOUBLE NUMBERS BIGGER THAN "<<biggerThan<<endl;
	numbers.doublesBiggerThan(Double(biggerThan));

	return 0;
}
