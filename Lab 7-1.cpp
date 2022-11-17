#include<iostream>
#include<cstring>
using namespace std;

class Employee
{
protected:
    char ime[50];
    int god, rab;
public:
    virtual double plata()=0;
    virtual double bonus()=0;
    Employee(char *i = " ", int g = 0, int god = 0)
    {
        strncpy(ime, i, 50);
        rab=god;
        god=g;
    }
    bool operator==(Employee &e)
    {
        if(god==e.god && bonus()==e.bonus())
        {
            return true;
        }
        return false;
    }
    virtual int tip()=0;
};

class SalaryEmployee : public Employee
{
private:
    double osnovna;
public:
    SalaryEmployee(char *i = " ", int g = 0, int god = 0, int op = 0) : Employee(i, g, god)
    {
        osnovna=op;
    }
    double bonus()
    {
        return osnovna*rab/100.;
    }
    double plata()
    {
        return osnovna+bonus();
    }
    int tip()
    {
        return 1;
    }
};

class HourlyEmployee : public Employee
{
private:
    int casovi;
    double hplata;
public:
    HourlyEmployee(char *i = " ", int g = 0, int god = 0, int bc = 0, int pc = 0) : Employee(i, g, god)
    {
        casovi=bc;
        hplata=pc;
    }
    double bonus()
    {
        if(casovi<=320)
        {
            return 0;
        }
        else
        {
            return (casovi-320)*0.5*hplata;
        }
    }
    double plata()
    {
        return casovi*hplata+bonus();
    }
    int tip()
    {
        return 2;
    }
};

class Freelancer : public Employee
{
private:
    int proekti;
    double *sumi;
public:
    Freelancer(char *i = " ", int god = 0, int isk = 0, int pr = 0, double *s = 0) : Employee(i, god, isk)
    {
        proekti=pr;
        sumi=new double[proekti];
        for(int j=0; j<proekti; j++)
        {
            sumi[j]=s[j];
        }
    }
    double bonus()
    {
        if(proekti<=5)
        {
            return 0;
        }
        else
        {
            return (proekti-5)*1000;
        }
    }
    double plata()
    {
        double sum=0;
        for(int i=0; i<proekti; i++)
        {
            sum+=sumi[i];
        }
        return sum+bonus();
    }
    int tip()
    {
        return 3;
    }
};

class Company
{
private:
    char ime[50];
    int n;
    Employee **e;
public:
    Company(char *i=" ")
    {
        strncpy(ime, i, 100);
        n=0;
        e=new Employee*[0];
    }
    Company &operator+=(Employee *emp)
    {
        Employee **temp=new Employee*[n+1];
        for(int i=0; i<n; i++)
        {
            temp[i]=e[i];
        }
        delete []e;
        e=temp;
        e[n++]=emp;
    }
    double vkupnaPlata()
    {
        double sum=0;
        for(int i=0; i<n; i++)
        {
            sum+=e[i]->plata();
        }
        return sum;
    }
    double filtriranaPlata(Employee * emp)
    {
        double sum=0;
        for(int i=0; i<n; i++)
        {
            if(*emp==*e[i])
            {
                sum+=e[i]->plata();
            }
        }
        return sum;
    }
    void pecatiRabotnici()
    {
        int sal=0, hou=0, fre=0;
        for(int i=0; i<n; i++)
        {
            switch (e[i]->tip())
            {
                case 1:
                    sal++;
                    break;
                case 2:
                    hou++;
                    break;
                case 3:
                    fre++;
                    break;
                default:
                    break;
            }
        }
        cout <<"Vo kompanijata "<<ime<<" rabotat:"<<endl
        << "Salary employees: "<<sal<<endl
        << "Hourly employees: " << hou << endl << "Freelancers: "
        << fre << endl;
    }
};

int main() {

char name[50];
cin >> name;
Company c(name);

int n;
cin >> n;

char employeeName[50];
int age;
int experience;
int type;

for (int i=0; i <n; ++i) {
  cin >> type;
  cin >> employeeName >> age >> experience;

  if (type == 1) {
    int basicSalary;
    cin >> basicSalary;
    c += new SalaryEmployee(employeeName, age, experience, basicSalary);
  }

  else if (type == 2) {
    int hoursWorked;
    int hourlyPay;
    cin >> hoursWorked >> hourlyPay;
    c += new HourlyEmployee(employeeName, age, experience, hoursWorked, hourlyPay);
  }

  else {
    int numProjects;
    cin >> numProjects;
    double projects[10];
    for (int i=0; i < numProjects; ++i) {
      cin >> projects[i];
    }
    c += new Freelancer(employeeName, age, experience, numProjects, projects);
  }
}

c.pecatiRabotnici();
cout << "Vkupnata plata e: " << c.vkupnaPlata() << endl;
Employee * emp = new HourlyEmployee("Petre_Petrov",31,6,340,80);
cout << "Filtriranata plata e: " << c.filtriranaPlata(emp);

delete emp;
}
