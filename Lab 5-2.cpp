#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber
{
private:
    double real, imaginary;
public:
    ComplexNumber(double r=0, double i=0)
    {
        real=r;
        imaginary=i;
    }
    double module()
    {
        return sqrt(pow(real, 2) + pow(imaginary, 2));
    }
    ComplexNumber &operator=(const ComplexNumber &c)
    {
        if(this!=&c)
        {
            real=c.real;
            imaginary=c.imaginary;
        }
        return *this;
    }
    friend ostream &operator<<(ostream &o, ComplexNumber &c)
    {
        if(c.real==0)
        {
            o<<c.imaginary<<"i"<<endl;
        }
        else if(c.imaginary==0)
        {
            o<<c.real<<endl;
        }
        else
        {
            o<<c.real<<"+"<<c.imaginary<<"i"<<endl;
        }
        return o;
    }
    ComplexNumber operator+(const ComplexNumber &c)
    {
        return ComplexNumber(real+c.real, imaginary+c.imaginary);
    }
    ComplexNumber operator-(const ComplexNumber &c)
    {
        return ComplexNumber(real-c.real, imaginary-c.imaginary);
    }
    ComplexNumber operator*(const ComplexNumber &c)
    {
        return ComplexNumber(real*c.real, imaginary*c.imaginary);
    }
    ComplexNumber operator/(const ComplexNumber &c)
    {
        if(c.real!=0 && c.imaginary!=0)
        {
            return ComplexNumber(real/c.real, imaginary/c.imaginary);
        }
    }
    bool operator ==(const ComplexNumber &c)
    {
        if(real==c.real && imaginary==c.imaginary)
        {
            return true;
        }
        return false;
    }
    bool operator>(const ComplexNumber &cn)
    {
        if(real > cn.real)
        {
            return true;
        }
        else if(cn.real > real)
        {
            return false;
        }
        else if(real == cn.real)
        {
            if(imaginary > cn.imaginary)
            {
                return true;
            }
            else if(cn.imaginary > imaginary)
            {
                return false;
            }
        }
    }

    bool operator<(const ComplexNumber &cn)
    {
        if(real > cn.real)
        {
            return false;
        }
        else if(cn.real > real)
        {
            return true;
        }
        else if(real == cn.real)
        {
            if(imaginary > cn.imaginary)
            {
                return false;
            }
            else if(cn.imaginary > imaginary)
            {
                return true;
            }
        }
    }
};

class Equation
{
private:
    ComplexNumber *numbers;
    char *znaci;
    int brK, brOp;
public:
    Equation()
    {
        brK=0;
        brOp=0;
        numbers=new ComplexNumber[0];
        znaci =new char[0];
    }
     Equation &operator+=(const ComplexNumber &cn)
    {
        ComplexNumber *temp = new ComplexNumber[brK + 1];
        for(int k = 0; k < brK; k++)
        {
            temp[k] = numbers[k];
        }
        delete [] numbers;
        numbers= temp;
        numbers[brK] = cn;
        brK++;
    }

    Equation &operator+=(const char &op)
    {
        char *tempop = new char[brOp + 1];
        for(int k = 0; k < brOp; k++)
        {
            tempop[k] = znaci[k];
        }
        delete [] znaci;
        znaci= tempop;
        znaci[brOp] = op;
        brOp++;
    }
    friend istream &operator>>(istream &in, Equation &e)
    {
        double r, i;
        char op=' ';
        for(int i=0; op!='='; i++)
        {
            in>>r>>i;
            e+=ComplexNumber(r, i);
            in>>op;
            e+=op;
        }
        e.brOp--;
        return in;
    }
    ComplexNumber result()
    {
        ComplexNumber res=numbers[0];
        ComplexNumber mRes;
        for(int i = 0, j = 1; i < brOp; i++, j++)
        {
            switch (znaci[i])
            {
                case '+':
                    res = numbers[j] + res;
                    break;
                case '-':
                    res = res - numbers[j];
                    break;
                case '*':
                    res = res * numbers[j];
                    break;
                case '/':
                    res = res / numbers[j];
                    break;
                default:
                    break;
            }
        }
        return res;
    }
    double sumModules()
    {
        double mod = 0;
        for(int i = 0; i < brK; i++)
        {
            mod +=numbers[i].module();
        }
    }
};

int main() {
	int testCase;
	double real, imaginary;
	ComplexNumber first, second, result;

	cin >> testCase;

	if (testCase <= 8) {
		cin >> real;
		cin >> imaginary;
		first = ComplexNumber(real, imaginary);
		cin >> real;
		cin >> imaginary;
		second = ComplexNumber(real, imaginary);
	}

	if (testCase == 1) {
		cout << "===== OPERATOR + =====" << endl;
		result = first + second;
		cout << result;
	}
	else if (testCase == 2) {
		cout << "===== OPERATOR - =====" << endl;
		result = first - second;
		cout << result;
	}
	else if (testCase == 3) {
		cout << "===== OPERATOR * =====" << endl;
		result = first * second;
		cout << result;
	}
	else if (testCase == 4) {
		cout << "===== OPERATOR / =====" << endl;
		result = first / second;
		cout << result;
	}
	else if (testCase == 5) {
		cout << "===== OPERATOR == =====" << endl;
		cout << first;
		cout << second;
		if (first == second)
			cout << "EQUAL" << endl;
		else
			cout << "NOT EQUAL" << endl;
	}
	else if (testCase == 6) {
		cout << "===== OPERATOR > =====" << endl;
		cout << first;
		cout << second;
		if (first > second)
			cout << "FIRST GREATER THAN SECOND" << endl;
		else
			cout << "FIRST LESSER THAN SECOND" << endl;
	}
	else if (testCase == 7) {
		cout << "===== OPERATOR < =====" << endl;
		cout << first;
		cout << second;
		if (first < second)
			cout << "FIRST LESSER THAN SECOND" << endl;
		else
			cout << "FIRST GREATER THAN SECOND" << endl;
	}
	else if (testCase == 8) {
		cout << "===== MODULE =====" << endl;
		double module = first.module();
		cout << first;
		cout << "Module: " << module << endl;
		cout << second;
		module = second.module();
		cout << "Module: " << module << endl;
	}
	else if (testCase == 9) {
		cout << "===== OPERATOR >> & SUM OF MODULES =====" << endl;
		Equation equation;
		cin >> equation;
		cout << equation.sumModules();
	}
	else if (testCase == 10) {
		cout << "===== EQUATION RESULT =====" << endl;
		Equation equation;
		cin >> equation;
		result = equation.result();
		cout << result;
	}
	return 0;
}
