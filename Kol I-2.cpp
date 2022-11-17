#include<iostream>
#include<cstring>
using namespace std;

class List
{
private:
    int *broevi;
    int n;

public:
    List()
    {
        broevi=new int[0];
        n=0;
    }
    List(int *broevi, int n)
    {
        this->broevi=new int[n+1];
        this->n=n;
        for(int i=0; i<n; i++)
        {
            this->broevi[i]=broevi[i];
        }
    }
    List(const List &l)
    {
        this->broevi=new int[l.n];
        this->n=l.n;
        for(int i=0; i<l.n; i++)
        {
            this->broevi[i]=l.broevi[i];
        }
    }
    ~List()
    {
        delete []broevi;
    }
    List &operator=(const List &l)
    {
        if(this!=&l)
        {
            delete []broevi;
            this->broevi=new int[l.n];
            this->n=l.n;
            for(int i=0; i<n; i++)
            {
                this->broevi[i]=l.broevi[i];
            }
        }
        return *this;
    }
    int Sum()
    {
        int sum=0;
        for(int i=0; i<n; i++)
        {
            sum+=broevi[i];
        }
        return sum;
    }
    float Average()
    {
        float average=Sum()/float(n);
        return average;
    }
    void pecati()
    {
        cout<<n<<": ";
        for(int i=0; i<n; i++)
        {
            cout<<broevi[i]<<" ";
        }
        cout<< "sum: "<<Sum()<<" average: "<<Average()<<endl;
    }
    friend class ListContainer;
};

class ListContainer
{
private:
    List *listi;
    int n;
    int obidi;
public:
    ListContainer()
    {
        obidi=0;
        n=0;
        listi=new List[0];
    }
    ListContainer(const ListContainer &lc)
    {
        this->obidi=lc.obidi;
        this->n=lc.n;
        this->listi=new List[lc.n];
        for(int i=0; i<n; i++)
        {
            this->listi[i]=lc.listi[i];
        }
    }
    ~ListContainer()
    {
        delete []listi;
    }
    ListContainer &operator=(const ListContainer &lc)
    {
        if(this!=&lc)
        {
            delete[]listi;
            this->obidi=lc.obidi;
            this->n=lc.n;
            this->listi=new List[lc.n];
            for(int i=0; i<n; i++)
            {
                this->listi[i]=lc.listi[i];
            }
        }
        return *this;
    }
    int sum()
    {
        int sum=0;
        for(int i=0; i<n; i++)
        {
            sum+=listi[i].Sum();
        }
        return sum;
    }
    float Average()
    {
        float average=0;
        int sumi=0, elementi=0;
        for(int i=0; i<n; i++)
        {
            sumi+=listi[i].Sum();
            elementi+=listi[i].n;
        }
        return float(sumi)/elementi;
    }
    void addNewList(List l)
    {
        obidi++;
        for(int i=0; i<n; i++)
        {
            if(l.Sum()==listi[i].Sum())
            {
                return ;
            }
        }
        List *tmp=new List[n+1];
        for(int i=0; i<n; i++)
        {
            tmp[i]=listi[i];
        }
        tmp[n++]=l;
        delete []listi;
        listi=tmp;
    }
    void print()
    {
        if(n== 0)
        {
            cout<<"The list is empty"<<endl;
            return;
        }
        else
        {int sum=0;
        float average=0;
        for(int i=0; i<n; i++)
        {
            cout<<"List number: "<<i+1<<" List info: ";
            listi[i].pecati();
            sum+=listi[i].Sum();
        }
        cout<<"Sum: "<<sum<<" Average: "<<Average()<<endl;
        cout<<"Successful attempts: "<<n<<" Failed attempts: "<<
        obidi-n<<endl;
        }
    }
};


int main() {

	ListContainer lc;
	int N;
	cin>>N;

	for (int i=0;i<N;i++) {
		int n;
		int niza[100];

		cin>>n;

		for (int j=0;j<n;j++){
			cin>>niza[j];

		}

		List l=List(niza,n);

		lc.addNewList(l);
	}


    int testCase;
    cin>>testCase;

    if (testCase==1) {
        cout<<"Test case for operator ="<<endl;
        ListContainer lc1;
        lc1.print();
        cout<<lc1.sum()<<" "<<lc.sum()<<endl;
        lc1=lc;
        lc1.print();
        cout<<lc1.sum()<<" "<<lc.sum()<<endl;
        lc1.sum();
        lc1.Average();

    }
    else {
        lc.print();
    }
}
