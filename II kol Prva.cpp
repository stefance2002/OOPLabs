#include<iostream>
#include<cstring>

using namespace std;

class Sneakers {
private:
    char model[50];
    int size;
    float price;

public:
    Sneakers(const char *model = "", int size = 38, float price = 1000) : size(size), price(price) {
        strncpy(this->model, model, 49);
        this -> model[49] = 0;
    }

    friend istream &operator>>(istream &in, Sneakers &s) {
        return in >> s.model >> s.size >> s.price;
    }

    friend ostream &operator<<(ostream &out, const Sneakers &s) {
        return out << "Model: " << s.model << " Size: " << s.size << " Price: " << s.price;
    }

    Sneakers &operator+=(float increment) {
        price += increment;
        return *this;
    }

    Sneakers &operator*=(float coefficient) {
        price *= coefficient;
        return *this;
    }

    bool operator==(Sneakers &s) {
        return strcmp(this->model, s.model) == 0 && this->size == s.size;
    }

    char *getModel() {
        return model;
    }

    int getSize() const {
        return size;
    }

    void setSize(int size) {
        this->size = size;
    }

    float getPrice() const {
        return price;
    }

    void setPrice(float price) {
        this->price = price;
    }
};

class SneakersShop
{
protected:
    char ime[50];
    Sneakers *patiki;
    int n;
    static int poskapuvanje;
public:
    SneakersShop(const char*i="")
    {
        strcpy(ime, i);
        patiki=new Sneakers[0];
        n=0;
    }
    ~SneakersShop()
    {
        delete[]patiki;
    }
    SneakersShop(const SneakersShop&s)
    {
        strcpy(ime, s.ime);
        n=s.n;
        patiki=new Sneakers[n];
        for(int i=0; i<n; i++)
        {
            patiki[i]=s.patiki[i];
        }
    }
    SneakersShop&operator=(const SneakersShop&s)
    {
        if(this!=&s)
        {
            strcpy(ime, s.ime);
            n=s.n;
            patiki=new Sneakers[n];
            for(int i=0; i<n; i++)
            {
                patiki[i]=s.patiki[i];
            }
        }
        return *this;
    }
    SneakersShop&operator+=(const Sneakers&s)
    {
        Sneakers *temp=new Sneakers[n+1];
        for(int i=0; i<n; i++)
        {
            temp[i]=patiki[i];
        }
        temp[n++]=s;
        delete[]patiki;
        patiki=temp;
        return *this;
    }
    virtual float checkItemAvailability(char* model, int size)
    {
        Sneakers a(model, size);
        for(int i=0; i<n; i++)
        {
            if(patiki[i]==a)
            {
                return patiki[i].getPrice();
            }
        }
        return 0;
    }
    SneakersShop&operator++()
    {
        for(int i=0; i<n; i++)
        {
            patiki[i]*=((100.0+poskapuvanje)/100);
        }
    }
    friend ostream&operator<<(ostream&out, const SneakersShop&s)
    {
        out<<"Sneakers shop: "<<s.ime<<endl;
        out<<"List of sneakers:"<<endl;
        if(s.n==0)
        {
            return out<<"EMPTY"<<endl;
        }
        for(int i=0; i<s.n; i++)
        {
            out<<i+1<<". "<<s.patiki[i]<<endl;
        }
    }
    static void setIncreasePercentage(int n)
    {
        poskapuvanje=n;
    }
};

class OnlineSneakersShop : public SneakersShop
{
private:
    char URL[100];
    static constexpr int popust=10;
public:
    OnlineSneakersShop(const char *i="", const char*u=""):SneakersShop(i)
    {
        strcpy(URL, u);
    }
    ~OnlineSneakersShop()
    {

    }
    float checkItemAvailability(char* model, int size)
    {
        Sneakers a(model, size);
        for(int i=0; i<n; i++)
        {
            if(patiki[i]==a)
            {
                return patiki[i].getPrice()*(100.0-popust)/100;
            }
        }
        return 0;
    }
    friend ostream&operator<<(ostream&out, const OnlineSneakersShop&s)
    {
        out<<"Online sneakers shop: "<<s.ime<<" URL: "<<s.URL<<endl;
        out<<"List of sneakers:"<<endl;
        if(s.n==0)
        {
            return out<<"EMPTY"<<endl;
        }
        for(int i=0; i<s.n; i++)
        {
            out<<i+1<<". "<<s.patiki[i]<<endl;
        }
    }
};

void printShop(SneakersShop *shop) {
    OnlineSneakersShop *casted = dynamic_cast<OnlineSneakersShop *>(shop);
    if (casted) {
        cout << (*casted);
    } else {
        cout << (*shop);
    }
}
int SneakersShop::poskapuvanje=5;

int main() {
    int testCase;
    cin >> testCase;
    char name[100];
    char url[100];

    if (testCase == 1) {
        cout << "TESTING CLASS SneakersShop: CONSTRUCTOR AND OPERATOR <<" << endl;
        cin >> name;
        SneakersShop shop(name);
        cout << shop;
    } else if (testCase == 2) {
        cout << "TESTING CLASS OnlineSneakersShop: CONSTRUCTOR AND OPERATOR <<" << endl;
        cin >> name >> url;
        OnlineSneakersShop shop(name, url);
        cout << shop;
    } else if (testCase == 3) {
        cout << "TESTING CLASS SneakersShop, CONSTRUCTOR, += and <<" << endl;
        cin >> name;
        SneakersShop shop(name);
        cout << shop;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            Sneakers s;
            cin >> s;
            shop += s;
        }
        cout << shop;
    } else if (testCase == 4) {
        cout << "TESTING CLASS OnlineSneakersShop, CONSTRUCTOR, += and <<" << endl;
        cin >> name >> url;
        OnlineSneakersShop shop(name, url);
        cout << shop;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            Sneakers s;
            cin >> s;
            shop += s;
        }
        cout << shop;
    } else if (testCase == 5) {
        cout << "TESTING METHOD checkItemAvailability" << endl;
        int typeOfShop;
        cin >> typeOfShop >> name; //0 = regular, 1 = online
        SneakersShop *shop;
        if (typeOfShop == 0) {
            shop = new SneakersShop(name);
        } else {
            cin >> url;
            shop = new OnlineSneakersShop(name, url);
        }
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            Sneakers s;
            cin >> s;
            (*shop) += s;
        }
        char model[100];
        int size;
        cin >> model >> size;
        cout << "Price for model " << model << " with size: " << size << " is: "
             << shop->checkItemAvailability(model, size) << endl;
    } else if (testCase == 6) {
        cout << "TESTING OPERATOR ++" << endl;
        int typeOfShop;
        cin >> typeOfShop >> name; //0 = regular, 1 = online
        SneakersShop *shop;
        if (typeOfShop == 0) {
            shop = new SneakersShop(name);
        } else {
            cin >> url;
            shop = new OnlineSneakersShop(name, url);
        }
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            Sneakers s;
            cin >> s;
            (*shop) += s;
        }
        cout << "BEFORE ++ IS CALLED" << endl;
        printShop(shop);
        ++(*shop);
        cout << "AFTER ++ IS CALLED" << endl;
        printShop(shop);
    } else if (testCase == 7) {
        cout << "TESTING OPERATOR ++ AND CHANGE OF STATIC MEMBER" << endl;
        int typeOfShop;
        cin >> typeOfShop >> name; //0 = regular, 1 = online
        SneakersShop *shop;
        if (typeOfShop == 0) {
            shop = new SneakersShop(name);
        } else {
            cin >> url;
            shop = new OnlineSneakersShop(name, url);
        }
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            Sneakers s;
            cin >> s;
            (*shop) += s;
        }

        cout << "BEFORE ++ IS CALLED" << endl;
        printShop(shop);
        ++(*shop);
        cout << "AFTER ++ IS CALLED" << endl;
        printShop(shop);

        cout <<"CHANGING INCREASE PERCENTAGE IN SneakersShop" << endl;
        SneakersShop::setIncreasePercentage(17);

        cout << "BEFORE ++ IS CALLED" << endl;
        printShop(shop);
        ++(*shop);
        cout << "AFTER ++ IS CALLED" << endl;
        printShop(shop);

    }


}
