#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class SMS
{
protected:
    float price;
    char primac[14];
public:
    SMS(const char *p="", float c=0)
    {
        price=c;
        strcpy(primac, p);
    }
    virtual float SMS_cena()=0;
    friend ostream &operator<<(ostream &out, SMS &s)
    {
        out<<"Tel: "<<s.primac<<" - cena: "<<s.SMS_cena()<<"den."<<endl;
    }
};

class RegularSMS : public SMS
{
private:
    char *text;
    bool roaming;
    static float rprocent;
public:
    RegularSMS(const char*p="", float c=0, const char*m="", bool r=false):SMS(p, c)
    {
        text=new char[strlen(m)+1];
        strcpy(text, m);
        roaming=r;
    }
    float SMS_cena()
    {
        int i=strlen(text);
        if(i&160==0)
        {
            i/=160;
        }
        else
        {
            i/=160;
            i++;
        }
        if(roaming)
        {
            return price*(rprocent+1)*i;
        }
        else
        {
            return price*1.18*i;
        }
    }
    static void set_rProcent(float t)
    {
        rprocent=t/100;
    }
};

class SpecialSMS : public SMS
{
private:
    bool specijalniceli;
    static float sprocent;
public:
    SpecialSMS(const char*p="", float c=0, bool s=false):SMS(p, c)
    {
        specijalniceli=s;
    }
    float SMS_cena()
    {
        if(!specijalniceli)
        {
            return price*(sprocent+1);
        }
        else
        {
            return price;
        }
    }
    static void set_sProcent(float t)
    {
        sprocent=t/100;
    }
};
void vkupno_SMS(SMS** poraka, int n)
{
    int r=0, s=0;
    float sumr=0, sums=0;
    for(int i=0; i<n; i++)
    {
        RegularSMS *temp=dynamic_cast<RegularSMS*>(poraka[i]);
        if(temp)
        {
            r++;
            sumr+=poraka[i]->SMS_cena();
        }
        else
        {
            s++;
            sums+=poraka[i]->SMS_cena();
        }
    }
    cout<<"Vkupno ima "<<r<<" regularni SMS poraki i nivnata cena e: "<<sumr<<endl;
    cout<<"Vkupno ima "<<s<<" specijalni SMS poraki i nivnata cena e: "<<sums<<endl;
}

float RegularSMS::rprocent=3;
float SpecialSMS::sprocent=1.5;

int main(){

	char tel[20], msg[1000];
	float cena;
	float price;
    int p;
	bool roam, hum;
	SMS  **sms;
	int n;
	int tip;

	int testCase;
	cin >> testCase;

	if (testCase == 1){
		cout << "====== Testing RegularSMS class ======" << endl;
		cin >> n;
		sms = new SMS *[n];

		for (int i = 0; i < n; i++){
			cin >> tel;
			cin >> cena;
            cin.get();
			cin.getline(msg, 1000);
			cin >> roam;
			cout << "CONSTRUCTOR" << endl;
			sms[i] = new RegularSMS(tel, cena, msg, roam);
			cout << "OPERATOR <<" << endl;
			cout << *sms[i];
		}
        for (int i = 0; i<n; i++) delete sms[i];
		delete[] sms;
	}
	if (testCase == 2){
		cout << "====== Testing SpecialSMS class ======" << endl;
		cin >> n;
		sms = new SMS *[n];

		for (int i = 0; i < n; i++){
			cin >> tel;
			cin >> cena;
			cin >> hum;
			cout << "CONSTRUCTOR" << endl;
			sms[i] = new SpecialSMS(tel, cena, hum);
			cout << "OPERATOR <<" << endl;
			cout << *sms[i];
		}
        for (int i = 0; i<n; i++) delete sms[i];
		delete[] sms;
	}
	if (testCase == 3){
		cout << "====== Testing method vkupno_SMS() ======" << endl;
		cin >> n;
		sms = new SMS *[n];

		for (int i = 0; i<n; i++){

			cin >> tip;
			cin >> tel;
			cin >> cena;
			if (tip == 1) {

				cin.get();
				cin.getline(msg, 1000);
                cin >> roam;

				sms[i] = new RegularSMS(tel, cena, msg, roam);

			}
			else {
				cin >> hum;

				sms[i] = new SpecialSMS(tel, cena, hum);
			}
		}

		vkupno_SMS(sms, n);
        for (int i = 0; i<n; i++) delete sms[i];
		delete[] sms;
	}
    if (testCase == 4){
		cout << "====== Testing RegularSMS class with a changed percentage======" << endl;
        SMS *sms1, *sms2;
        	cin >> tel;
			cin >> cena;
            cin.get();
			cin.getline(msg, 1000);
			cin >> roam;
			sms1 = new RegularSMS(tel, cena, msg, roam);
			cout << *sms1;

            cin >> tel;
			cin >> cena;
            cin.get();
			cin.getline(msg, 1000);
			cin >> roam;
        	cin >> p;
        	RegularSMS::set_rProcent(p);
        	sms2 = new RegularSMS(tel, cena, msg, roam);
        	cout << *sms2;

        delete sms1, sms2;
	}
    if (testCase == 5){
		cout << "====== Testing SpecialSMS class with a changed percentage======" << endl;
        SMS *sms1, *sms2;
        	cin >> tel;
			cin >> cena;
			cin >> hum;
			sms1 = new SpecialSMS(tel, cena, hum);
			cout << *sms1;

            cin >> tel;
			cin >> cena;
			cin >> hum;
        	cin >> p;
        	SpecialSMS::set_sProcent(p);
        	sms2 = new SpecialSMS(tel, cena, hum);
        	cout << *sms2;

        delete sms1, sms2;
	}

	return 0;
}
