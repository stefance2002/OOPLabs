#include<iostream>
#include<cstring>
using namespace std;

class Category
{
private:
    char name[20];
public:
    Category()
    {
        strcpy(name, "unnamed");
    }
    Category(char *c)
    {
        strcpy(name, c);
    }
    void print()
    {
        cout<<"Category: "<<name<<endl;
    }
};

class NewsArticle
{
private:
    Category cat;
    char title[30];
public:
    NewsArticle()
    {
        strcpy(title,"untitled");
        Category();
    }
    NewsArticle(Category c, char *a)
    {
        cat=c;
        strcpy(title, a);
    }
    NewsArticle(Category c)
    {
        cat=c;
        strcpy(title,"untitled");
    }
    void print()
    {
        cout<<"Article title: "<<title<<endl;
        cat.print();
    }
};

class FrontPage
{
private:
    NewsArticle na;
    float price;
    int editionNumber;
public:
    FrontPage()
    {
        price=0;
        editionNumber=0;
        NewsArticle();
    }
    FrontPage(NewsArticle n, float p, int e)
    {
        na=n;
        price=p;
        editionNumber=e;
    }
    FrontPage(NewsArticle n, float p)
    {
        na=n;
        price=p;
        editionNumber=0;
    }
    void print()
    {
        cout<<"Price: "<<price<<", Edition number: "<<editionNumber<<endl;
        na.print();
    }
};
int main() {
	char categoryName[20];
	char articleTitle[30];
	float price;
	int editionNumber;

	int testCase;
	cin >> testCase;


	if (testCase == 1) {
		int iter;
		cin >> iter;
		while (iter > 0) {
			cin >> categoryName;
			cin >> articleTitle;
			cin >> price;
			cin >> editionNumber;
			Category category(categoryName);
			NewsArticle article(category, articleTitle);
			FrontPage frontPage(article, price, editionNumber);
			frontPage.print();
			iter--;
		}
	}
	else if (testCase == 2) {
		cin >> categoryName;
		cin >> price;
		cin >> editionNumber;
		Category category(categoryName);
		NewsArticle article(category);
		FrontPage frontPage(article, price, editionNumber);
		frontPage.print();
	}// test case 3
	else if (testCase == 3) {
		cin >> categoryName;
		cin >> articleTitle;
		cin >> price;
		Category category(categoryName);
		NewsArticle article(category, articleTitle);
		FrontPage frontPage(article, price);
		frontPage.print();
	}
    else {
    	FrontPage frontPage = FrontPage();
        frontPage.print();
    }
	return 0;
}
