#include<iostream>
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
    List(int *br, int n=0)
    {
        broevi=new int [0];
        for(int i=0; i<n; i++)
        {
            broevi[i]=br[i];
        }
        this->n=n;
    }

    List(const List&l)
    {
        broevi=new int[l.n];
        n=l.n;
        for(int i=0; i<n; i++)
        {
            broevi[i]=l.broevi[i];
        }
    }

    List &operator=(List &l)
    {
        if(this!=&l)
        {
            delete[]broevi;
            broevi=new int[l.n];
            n=l.n;
            for(int i=0; i<n; i++)
            {
                broevi[i]=l.broevi[i];
            }
        }
        return *this;
    }
    ~List()
    {
        delete[]broevi;
    }

    void pecati()
    {
        cout<<n<<":";
        for(int i=0; i<n; i++)
        {
            cout<<" "<<broevi[i];
        }
        cout<<" sum: "<<sum();
        cout<<" average: "<<average()<<endl;
    }

   int sum()
    {
        int s=0;
        for(int i=0; i<n; i++)
        {
            s+=broevi[i];
        }
        return s;
    }
    float average()
    {
        int s=sum();
        return (float)s/n;
    }
    int getn()
    {
        return n;
    }

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
        listi=new List[0];
        obidi=0;
        n=0;
    }
    ListContainer(const ListContainer&lc)
    {
        listi=new List[lc.n];
        for(int i=0; i<lc.n; i++)
        {
            listi[i]=lc.listi[i];
        }
        obidi=lc.obidi;
        n=lc.n;
    }
    ~ListContainer()
    {
        delete[]listi;
    }
    ListContainer&operator=(const ListContainer&lc)
    {
        if(this!=&lc)
        {
            delete[]listi;
            listi=new List[lc.n];
            for(int i=0; i<lc.n; i++)
            {
                listi[i]=lc.listi[i];
            }
            obidi=lc.obidi;
            n=lc.n;
        }
        return *this;
    }

    void print()
    {
         if(n > 0)
        {
            for(int i = 0; i < n; i++)
            {
                cout << "List number: " << i + 1;
                cout << " List info: ";
                listi[i].pecati();
            }
            cout << "Sum: " << sum() << " Average: " << average() << endl;
            cout << "Successful attempts: " << n << " Failed attempts: " << obidi - n << endl;
        }
        else
        {
            cout << "The list is empty" << endl;
        }
    }
    int sum()
    {
        int globSum = 0;
        for(int i = 0; i < n; i++)
        {
            globSum += listi[i].sum();
        }
        return globSum;
    }

    double average()
    {
        int globElementi = 0;
        for(int i = 0; i < n; i++)
        {
            globElementi += listi[i].getn();
        }
        return sum() / (double) globElementi;
    }

    void addNewList(List l)
    {
        for(int i=0; i<n; i++)
        {
            if(listi[i].sum()==l.sum())
            {
                obidi++;
                return;
            }
        }
        List *temp=new List[n+1];
        for(int i=0; i<n; i++)
        {
            temp[i]=listi[i];
        }
        delete[]listi;
        listi=temp;
        listi[n++]=l;
        obidi++;
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
        lc1.average();

    }
    else {
        lc.print();
    }
    return 0;
}
