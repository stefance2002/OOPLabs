#include <iostream>
using namespace std;

class Agol
{
private:
    int deg;
    int minn;
    int sec;
public:
    Agol()
    {
        deg=0;
        minn=0;
        sec=0;
    }

    void setstepeni(int d)
    {
        deg=d;
    }
    void setminuti(int m)
    {
        minn=m;
    }
    void setsekundi(int s)
    {
        sec=s;
    }
    int getstepeni()
    {
        return deg;
    }
    int getminuti()
    {
        return minn;
    }
    int getsekundi()
    {
        return sec;
    }

    void tosekundi()
    {
        cout <<(deg*3600+minn*60+sec);
    }
};


bool changeOfSeconds(Agol a, int sec){
	return a.getsekundi()!=sec;
}

bool proveri(int deg, int minn, int sec)
{
    if((deg>0 && deg<361) && (minn>0 && minn<61) && (sec>=0 && sec<61))
    {
        return 1;
    }
    else return 0;
}

int main() {

    //da se instancira objekt od klasata Agol
    Agol a;
    int deg, minn, sec;
    cin >> deg >> minn >> sec;

    if (proveri(deg, minn, sec))
    {
    	a.setstepeni(deg);
        a.setminuti(minn);
        a.setsekundi(sec);
        a.tosekundi();
        if (changeOfSeconds(a,sec))
			cout << "Ne smeete da gi menuvate sekundite vo ramkite na klasata!" << endl;

    }
    else
    {
        cout<<"Nevalidni vrednosti za agol";
    }

    return 0;
}
