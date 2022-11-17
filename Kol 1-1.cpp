#include<iostream>
#include<cstring>
using namespace std;

class Book
{
protected:
    char ISBN[20];
    char naslov[50];
    char avtor[30];
    float cena;
public:
    Book(const char *ISBN2="", const char*naslov2="", const char *avtor2="", float cena2=0)
    {
        strcpy(ISBN, ISBN2);
        strcpy(naslov, naslov2);
        strcpy(avtor, avtor2);
        cena=cena2;
    }
    virtual float bookPrice()=0;
    bool operator>(Book &b2)
    {
        return bookPrice()>b2.bookPrice();
    }
     friend ostream &operator<<(ostream &o, Book &b)
    {
        return o<<b.ISBN<<": "<<b.naslov<<", "<<b.avtor<<" "<< b.bookPrice() << endl;
    }
    void setISBN(char *ISBN2)
    {
        strcpy(ISBN, ISBN2);
    }
};

class OnlineBook : public Book
{
private:
    char *url;
    int golemina;
public:
    OnlineBook(const char *ISBN2="", const char*naslov2="", const char *avtor2="", float cena2=0, const char *url2="", int golemina2=0): Book(ISBN2, naslov2, avtor2, cena2)
    {
        url=new char[strlen(url2)+1];
        strcpy(url, url2);
        golemina=golemina2;
    }
    float bookPrice()
    {
        if(golemina>20)
        {
            return cena*1.2;
        }
        return cena;
    }
};

class PrintBook : public Book
{
private:
    float kg;
    bool zaliha;
public:

    PrintBook(const char *ISBN2="", const char*naslov2="", const char *avtor2="", float cena2=0, float kg2=0, bool zaliha2=false) : Book(ISBN2, naslov2, avtor2, cena2)
    {
        kg=kg2;
        zaliha=zaliha2;
    }
    float bookPrice()
    {
        if(kg>0.7)
        {
            return cena*1.15;
        }
        return cena;
    }
};

void mostExpensiveBook (Book** books, int n)
{
    cout << "FINKI-Education" << endl;
    int online=0, print=0, maxI=0;
    for(int i=0; i<n; i++)
    {
        OnlineBook*temp=dynamic_cast<OnlineBook*>(books[i]);
        if(temp!=0)
        {
            online++;
        }
        else
        {
            print++;
        }
        if(*books[i]>*books[maxI])
        {
            maxI=i;
        }
    }
    cout<<"Total number of online books: "<<online<<endl;
    cout<<"Total number of print books: "<<print<<endl;
    cout<<"The most expensive book is:"<<endl;
    cout<<*books[maxI]<<endl;
}

int main(){

	char isbn[20], title[50], author[30], url[100];
	int size, tip;
	float price, weight;
	bool inStock;
	Book  **books;
	int n;

	int testCase;
	cin >> testCase;

	if (testCase == 1){
		cout << "====== Testing OnlineBook class ======" << endl;
		cin >> n;
		books = new Book *[n];

		for (int i = 0; i < n; i++){
			cin >> isbn;
			cin.get();
			cin.getline(title, 50);
			cin.getline(author, 30);
			cin >> price;
			cin >> url;
			cin >> size;
			cout << "CONSTRUCTOR" << endl;
			books[i] = new OnlineBook(isbn, title, author, price, url, size);
			cout << "OPERATOR <<" << endl;
			cout << *books[i];
		}
		cout << "OPERATOR >" << endl;
		cout << "Rezultat od sporedbata e: " << endl;
		if (*books[0] > *books[1])
			cout << *books[0];
		else
			cout << *books[1];
	}
	if (testCase == 2){
		cout << "====== Testing OnlineBook CONSTRUCTORS ======" << endl;
		cin >> isbn;
		cin.get();
		cin.getline(title, 50);
		cin.getline(author, 30);
		cin >> price;
		cin >> url;
		cin >> size;
		cout << "CONSTRUCTOR" << endl;
		OnlineBook ob1(isbn, title, author, price, url, size);
		cout << ob1 << endl;
		cout << "COPY CONSTRUCTOR" << endl;
		OnlineBook ob2(ob1);
		cin >> isbn;
		ob2.setISBN(isbn);
		cout << ob1 << endl;
		cout << ob2 << endl;
		cout << "OPERATOR =" << endl;
		ob1 = ob2;
		cin >> isbn;
		ob2.setISBN(isbn);
		cout << ob1 << endl;
		cout << ob2 << endl;
	}
	if (testCase == 3){
		cout << "====== Testing PrintBook class ======" << endl;
		cin >> n;
		books = new Book *[n];

		for (int i = 0; i < n; i++){
			cin >> isbn;
			cin.get();
			cin.getline(title, 50);
			cin.getline(author, 30);
			cin >> price;
			cin >> weight;
			cin >> inStock;
			cout << "CONSTRUCTOR" << endl;
			books[i] = new PrintBook(isbn, title, author, price, weight, inStock);
			cout << "OPERATOR <<" << endl;
			cout << *books[i];
		}
		cout << "OPERATOR >" << endl;
		cout << "Rezultat od sporedbata e: " << endl;
		if (*books[0] > *books[1])
			cout << *books[0];
		else
			cout << *books[1];
	}
	if (testCase == 4){
		cout << "====== Testing method mostExpensiveBook() ======" << endl;
		cin >> n;
		books = new Book *[n];

		for (int i = 0; i<n; i++){

			cin >> tip >> isbn;
			cin.get();
			cin.getline(title, 50);
			cin.getline(author, 30);
			cin >> price;
			if (tip == 1) {

				cin >> url;
				cin >> size;

				books[i] = new OnlineBook(isbn, title, author, price, url, size);

			}
			else {
				cin >> weight;
				cin >> inStock;

				books[i] = new PrintBook(isbn, title, author, price, weight, inStock);
			}
		}

		mostExpensiveBook(books, n);
	}

	for (int i = 0; i<n; i++) delete books[i];
		delete[] books;
	return 0;
}
