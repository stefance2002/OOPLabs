#include<iostream>
#include<cstring>
using namespace std;
#define MAX 100
enum typeC{standard, loyal, vip};

class UserExistsException
{
public:
    void print()
    {
        cout<<"The user already exists in the list!"<<endl;
    }
};

class Customer
{
private:
    char ime[50], email[50];
    typeC vid;
    static int osnoven;
    static const int dopolnitelen=20;
    int n;
public:
    Customer(const char*i="", const char*e="", typeC c=(typeC)0, int nn=0)
    {
        strcpy(ime, i);
        strcpy(email, e);
        vid=c;
        n=nn;
    }
    Customer(const Customer&c)
    {
        strcpy(ime, c.ime);
        strcpy(email, c.email);
        vid=c.vid;
        n=c.n;
    }
    Customer &operator=(const Customer &c)
    {
        if(this!=&c)
        {
            strcpy(ime, c.ime);
            strcpy(email, c.email);
            vid=c.vid;
            n=c.n;
        }
        return *this;
    }
    friend ostream &operator<<(ostream &out, Customer &c)
    {
        out<<c.ime<<endl;
        out<<c.email<<endl;
        out<<c.n<<endl;
        if(c.vid==0)
        {
            out<<"standard"<<" 0"<<endl;
        }
        else if(c.vid==1)
        {
            out<<"loyal "<<c.osnoven<<endl;
        }
        else
        {
            out<<"vip "<<c.dopolnitelen+c.osnoven<<endl;
        }
        return out;
    }
    char*getIme()
    {
        return email;
    }
    void setDiscount1(int n)
    {
        osnoven=n;
    }
    typeC getVid()
    {
        return vid;
    }
    void setVid(typeC c)
    {
        vid=c;
    }
    int getN()
    {
        return n;
    }
};

class FINKI_bookstore
{
private:
    Customer *kupuvaci;
    int n;
public:
    FINKI_bookstore(Customer *c=0, int nn=0)
    {
        n=nn;
        kupuvaci=new Customer[n];
        for(int i=0; i<n; i++)
        {
            kupuvaci[i]=c[i];
        }
    }
    FINKI_bookstore(const FINKI_bookstore &f)
    {
        n=f.n;
        kupuvaci=new Customer[n];
        for(int i=0; i<n; i++)
        {
            kupuvaci[i]=f.kupuvaci[i];
        }
    }
    FINKI_bookstore&operator=(const FINKI_bookstore &f)
    {
        if(this!=&f)
        {
            delete[]kupuvaci;
            n=f.n;
            kupuvaci=new Customer[n];
            for(int i=0; i<n; i++)
            {
                kupuvaci[i]=f.kupuvaci[i];
            }
        }
        return *this;
    }
    ~FINKI_bookstore()
    {
        delete[]kupuvaci;
    }
    FINKI_bookstore &operator+=(Customer &c)
    {
        for(int i=0; i<n; i++)
        {
            if(!strcmp(kupuvaci[i].getIme(), c.getIme()))
            {
                throw UserExistsException();
            }
        }
        Customer *temp=new Customer[n+1];
        for(int i=0; i<n; i++)
        {
            temp[i]=kupuvaci[i];
        }
        temp[n++]=c;
        delete[]kupuvaci;
        kupuvaci=temp;
        return *this;
    }
    void update()
    {
        for(int i=0; i<n; i++)
        {
            if(kupuvaci[i].getVid()==0 && kupuvaci[i].getN()>5)
            {
                kupuvaci[i].setVid((typeC)1);
            }
            else if(kupuvaci[i].getVid()==1 && kupuvaci[i].getN()>10)
            {
                kupuvaci[i].setVid((typeC)2);
            }
        }
    }
    friend ostream&operator<<(ostream&out, FINKI_bookstore &f)
    {
        for(int i=0; i<f.n; i++)
        {
            out<<f.kupuvaci[i];
        }
        return out;
    }
    void setCustomers(Customer *k, int nn)
    {
        delete[]kupuvaci;
        kupuvaci=new Customer[nn];
        for(int i=0; i<nn; i++)
        {
            kupuvaci[i]=k[i];
        }
        n=nn;
    }
};

int Customer::osnoven=10;

int main(){
  int testCase;
  cin >> testCase;

  char name[MAX];
  char email[MAX];
  int tC;
  int discount;
  int numProducts;


  if (testCase == 1){
    cout << "===== Test Case - Customer Class ======" << endl;
    cin.get();
    cin.getline(name,MAX);
    cin.getline(email,MAX);
    cin >> tC;
    cin >> numProducts;
    cout << "===== CONSTRUCTOR ======" << endl;
    Customer c(name, email, (typeC) tC, numProducts);
    cout << c;

  }

  if (testCase == 2){
    cout << "===== Test Case - Static Members ======" << endl;
    cin.get();
    cin.getline(name,MAX);
    cin.getline(email,MAX);
    cin >> tC;
    cin >> numProducts;
    cout << "===== CONSTRUCTOR ======" << endl;
    Customer c(name, email, (typeC) tC, numProducts);
    cout << c;

    c.setDiscount1(5);

    cout << c;
  }

  if (testCase == 3){
    cout << "===== Test Case - FINKI-bookstore ======" << endl;
    FINKI_bookstore fc;
    int n;
    cin >> n;
    Customer customers[MAX];
    for(int i = 0; i < n; ++i) {
      cin.get();
      cin.getline(name,MAX);
      cin.getline(email,MAX);
      cin >> tC;
      cin >> numProducts;
      Customer c(name, email, (typeC) tC, numProducts);
      customers[i] = c;
    }

    fc.setCustomers(customers, n);

    cout << fc <<endl;
  }

  if (testCase == 4){
    cout << "===== Test Case - operator+= ======" << endl;
    FINKI_bookstore fc;
    int n;
    cin >> n;
    Customer customers[MAX];
    for(int i = 0; i < n; ++i) {
      cin.get();
      cin.getline(name,MAX);
      cin.getline(email,MAX);
      cin >> tC;
      cin >> numProducts;
      Customer c(name, email, (typeC) tC, numProducts);
      customers[i] = c;
    }

    fc.setCustomers(customers, n);
    cout << "OPERATOR +=" << endl;
    cin.get();
    cin.getline(name,MAX);
    cin.getline(email,MAX);
    cin >> tC;
    cin >> numProducts;
    Customer c(name, email, (typeC) tC, numProducts);
    fc+=c;

    cout << fc;
  }

  if (testCase == 5){
    cout << "===== Test Case - operator+= (exception) ======" << endl;
    FINKI_bookstore fc;
    int n;
    cin >> n;
    Customer customers[MAX];
    Customer k;
    for(int i = 0; i < n; ++i) {
      cin.get();
      cin.getline(name,MAX);
      cin.getline(email,MAX);
      cin >> tC;
      cin >> numProducts;
      Customer c(name, email, (typeC) tC, numProducts);
      customers[i] = c;
      k=c;
    }

    fc.setCustomers(customers, n);
    cout << "OPERATOR +=" << endl;
    cin.get();
    cin.getline(name,MAX);
    cin.getline(email,MAX);
    cin >> tC;
    cin >> numProducts;

    try
    {
        fc+=k;
    }
    catch(UserExistsException &c)
    {
        c.print();
    }

    cout << fc;
  }

  if (testCase == 6){
    cout << "===== Test Case - update method  ======" << endl << endl;
    FINKI_bookstore fc;
    int n;
    cin >> n;
    Customer customers[MAX];
    for(int i = 0; i < n; ++i) {
      cin.get();
      cin.getline(name,MAX);
      cin.getline(email,MAX);
      cin >> tC;
      cin >> numProducts;
      Customer c(name, email, (typeC) tC, numProducts);
      customers[i] = c;
    }

    fc.setCustomers(customers, n);

    cout << "Update:" << endl;
    fc.update();
    cout << fc;
  }
  return 0;

}
