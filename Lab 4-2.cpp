#include<iostream>
#include<cstring>
using namespace std;

enum Extension{pdf, text, exe};

class File
{
private:
    char*ime;
    Extension tip;
    char*sops;
    int golemina;
public:
    File(char *ime="", char *sops="", int golemina=0, Extension tip=(Extension)0)
    {
        this->ime=new char[strlen(ime)+1];
        strcpy(this->ime, ime);
        this->sops=new char[strlen(sops)+1];
        strcpy(this->sops, sops);
        this->golemina=golemina;
        this->tip=tip;
    }
    File(const File &f)
    {
        ime=new char[strlen(f.ime)+1];
        strcpy(ime, f.ime);
        sops=new char[strlen(f.sops)+1];
        strcpy(sops, f.sops);
        golemina=f.golemina;
        tip=f.tip;
    }
    ~File()
    {
        delete[]sops;
        delete[]ime;
    }
    File &operator=(const File &f)
    {
        if(this!=&f)
        {
            delete[]sops;
            delete[]ime;
            ime=new char[strlen(f.ime)+1];
            strcpy(ime, f.ime);
            sops=new char[strlen(f.sops)+1];
            strcpy(sops, f.sops);
            golemina=f.golemina;
            tip=f.tip;
        }
        return *this;
    }
    void print()
    {
        cout<<"File name: "<<ime;
        if(tip==0)
            cout<<".pdf"<<endl;
        if(tip==1)
            cout<<".txt"<<endl;
        if(tip==2)
        cout<<".exe"<<endl;
        cout<<"File owner: "<<sops<<endl;
        cout<<"File size: "<<golemina<<endl;
    }
    bool equals(const File &that)
    {
        if(strcmp(ime, that.ime)==0 && strcmp(sops, that.sops)==0 && tip==that.tip)
        {
            return true;
        }
        return false;
    }
    bool equalsType(const File & that)
    {
        if(strcmp(ime, that.ime)==0 && tip==that.tip)
        {
            return true;
        }
        return false;
    }
};

class Folder
{
private:
    char*ime;
    int n;
    File *datoteki;
public:
    Folder(const char*name="")
    {
        ime=new char[strlen(name)+1];
        strcpy(ime, name);
        n=0;
        datoteki=NULL;
    }
    Folder(const Folder &f)
    {
        ime=new char[strlen(f.ime)+1];
        strcpy(ime, f.ime);
        n=f.n;
        datoteki=new File[n];
        for(int i=0; i<n; i++)
        {
            datoteki[i]=f.datoteki[i];
        }
    }
    ~Folder()
    {
        delete[]ime;
        delete[]datoteki;
    }
    Folder &operator=(const Folder&f)
    {
        if(this!=&f)
        {
            delete[]ime;
            delete[]datoteki;
            ime=new char[strlen(f.ime)+1];
            strcpy(this->ime, f.ime);
            n=f.n;
            for(int i=0;i<f.n;i++)
        {
            datoteki[i]=f.datoteki[i];
        }
        }
        return *this;
    }
    void print()
    {
        cout<<"Folder name: "<<ime<<endl;
        for(int i=0; i<n; i++)
        {
            datoteki[i].print();
        }
    }
    void remove(File & file)
    {
        File*tmp=new File[n-1];
        int j=0;
        for(int i=0; i<n; i++)
        {
            if(datoteki[i].equals(file))
            {
                continue;
            }
            else
            {
                tmp[j++]=datoteki[i];
            }
            delete []datoteki;
            datoteki=tmp;
            n--;
        }
    }
    void add(File & file)
    {
        File *tmp=new File[n+1];
        for(int i=0; i<n; i++)
        {
            tmp[i]=datoteki[i];
        }
        tmp[n++]=file;
        delete[]datoteki;
        datoteki=tmp;
    }
};

int main() {
	char fileName[20];
	char fileOwner[20];
	int ext;
	int fileSize;

	int testCase;
	cin >> testCase;
	if (testCase == 1) {
		cout << "======= FILE CONSTRUCTORS AND = OPERATOR =======" << endl;
		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;

		File created = File(fileName, fileOwner, fileSize, (Extension) ext);
		File copied = File(created);
		File assigned = created;

		cout << "======= CREATED =======" << endl;
		created.print();
		cout << endl;
        cout << "======= COPIED =======" << endl;
		copied.print();
		cout << endl;
        cout << "======= ASSIGNED =======" << endl;
		assigned.print();
	}
	else if (testCase == 2) {
		cout << "======= FILE EQUALS AND EQUALS TYPE =======" << endl;
		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;

		File first(fileName, fileOwner, fileSize, (Extension) ext);
		first.print();

		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;

		File second(fileName, fileOwner, fileSize, (Extension) ext);
		second.print();

		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;

		File third(fileName, fileOwner, fileSize, (Extension) ext);
		third.print();

		bool equals = first.equals(second);
		cout << "FIRST EQUALS SECOND: ";
		if (equals)
			cout << "TRUE" << endl;
		else
			cout << "FALSE" << endl;

		equals = first.equals(third);
		cout << "FIRST EQUALS THIRD: ";
		if (equals)
			cout << "TRUE" << endl;
		else
			cout << "FALSE" << endl;

		bool equalsType = first.equalsType(second);
		cout << "FIRST EQUALS TYPE SECOND: ";
		if (equalsType)
			cout << "TRUE" << endl;
		else
			cout << "FALSE" << endl;

		equalsType = second.equals(third);
		cout << "SECOND EQUALS TYPE THIRD: ";
		if (equalsType)
			cout << "TRUE" << endl;
		else
			cout << "FALSE" << endl;

	}
	else if (testCase == 3) {
		cout << "======= FOLDER CONSTRUCTOR =======" << endl;
		cin >> fileName;
		Folder folder(fileName);
		folder.print();

	}
	else if (testCase == 4) {
		cout << "======= ADD FILE IN FOLDER =======" << endl;
		char name[20];
		cin >> name;
		Folder folder(name);

		int iter;
		cin >> iter;

		while (iter > 0) {
			cin >> fileName;
			cin >> fileOwner;
			cin >> fileSize;
			cin >> ext;

			File file(fileName, fileOwner, fileSize, (Extension) ext);
			folder.add(file);
			iter--;
		}
		folder.print();
	}
	else {
		cout << "======= REMOVE FILE FROM FOLDER =======" << endl;
		char name[20];
		cin >> name;
		Folder folder(name);

		int iter;
		cin >> iter;

		while (iter > 0) {
			cin >> fileName;
			cin >> fileOwner;
			cin >> fileSize;
			cin >> ext;

			File file(fileName, fileOwner, fileSize, (Extension) ext);
			folder.add(file);
			iter--;
		}
		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;

		File file(fileName, fileOwner, fileSize, (Extension) ext);
		folder.remove(file);
		folder.print();
	}
	return 0;
}
