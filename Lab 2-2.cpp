#include <iostream>
using namespace std;

class Krug {
private:
    float radius;
    const float pi=3.14;
public:
    Krug()
    {
        radius=3;
    }
    Krug(float r)
    {
        radius=r;
    }
    float plostina()
    {
        return radius*radius*pi;
    }
    float perimetar()
    {
        return 2*radius*pi;
    }
    bool check()
    {
        if(plostina()==perimetar())
        {
            return 1;
        }
        else return 0;
    }
};

int main() {
	float r;
	cin >> r;
    Krug k(r);
	//instanciraj objekt od klasata Krug cij radius e vrednosta procitana od tastatura

	cout << k.perimetar() << endl;
	cout << k.plostina() << endl;
	cout << k.check() <<endl;
    //instanciraj objekt od klasata Krug cij radius ne e definiran

    Krug k1;
    cout << k1.perimetar() << endl;
	cout << k1.plostina() << endl;
	cout << k1.check() <<endl;
	return 0;
}
