#include <iostream>
#include <cstring>
using namespace std;

class CovidVaccine
{
protected:
    char proizvoditel[100];
    char *ime;
    double koef;
public:
    CovidVaccine(const char*p="", const char*i="", double k=0)
    {
        strcpy(proizvoditel, p);
        ime=new char[strlen(i)+1];
        strcpy(ime, i);
        koef=k;
    }
    virtual double calculateVaccineEfficiency()=0;
    bool operator<=(CovidVaccine&c)
    {
        return koef<=c.koef;
    }
};

class GeneticVaccine : public CovidVaccine
{
private:
    int mehanizam;
public:
    GeneticVaccine(const char*p="", const char*i="", double k=0, int m=0):CovidVaccine(p,i,k)
    {
        mehanizam=m;
    }
    double calculateVaccineEfficiency()
    {
        if(mehanizam==0)
        {
            return koef*1.35;
        }
        else if(mehanizam==1)
        {
            return koef*1.55;
        }
    }
    friend ostream &operator<<(ostream&out, GeneticVaccine&c)
    {
        out<<"Vaccine info: "<<c.ime<<" - "<<c.proizvoditel<<" - "<<c.calculateVaccineEfficiency()<<endl;
        out<<"Mechanism for storing genetic information: ";
        if(c.mehanizam==0)
        {
            out<<"RNA"<<endl;
        }
        else
        {
            out<<"DNA"<<endl;
        }
        return out;
    }
    bool operator<=(CovidVaccine&c)
    {
        return calculateVaccineEfficiency()<=c.calculateVaccineEfficiency();
    }
};

class InactivatedVaccine : public CovidVaccine
{
private:
    int sostojka;
public:
    InactivatedVaccine(const char*p="", const char*i="", double k=0, int m=0):CovidVaccine(p,i,k)
    {
        sostojka=m;
    }
    double calculateVaccineEfficiency()
    {
        if(sostojka==0)
        {
            return koef*0.9;
        }
        else if(sostojka==1)
        {
            return koef*1.12;
        }
        else if(sostojka==2)
        {
            return koef*0.85;
        }
        else if(sostojka==3)
        {
            return koef*1.2;
        }
    }
    friend ostream &operator<<(ostream&out, InactivatedVaccine&c)
    {
        out<<"Vaccine info: "<<c.ime<<" - "<<c.proizvoditel<<" - "<<c.calculateVaccineEfficiency()<<endl;
        out<<"The vaccine consists of the following ingredient: ";
        if(c.sostojka==0)
        {
            out<<"DMG"<<endl;
        }
        else if(c.sostojka==1)
        {
            out<<"PEG"<<endl;
        }
        else if(c.sostojka==2)
        {
            out<<"SM_102"<<endl;
        }
        else if(c.sostojka==3)
        {
            out<<"DPSC"<<endl;
        }
        return out;
    }
    bool operator<=(InactivatedVaccine&c)
    {
        return calculateVaccineEfficiency()<=c.calculateVaccineEfficiency();
    }
};

void mostEffectiveInactivatedVaccine(CovidVaccine **c, int n)
{
    int maxkoef=0;
    for(int i=0; i<n; i++)
    {
        InactivatedVaccine *temp=dynamic_cast<InactivatedVaccine*>(c[i]);
        if(temp && *c[maxkoef]<=*c[i])
        {
            maxkoef=i;
        }
    }
    InactivatedVaccine *temp=dynamic_cast<InactivatedVaccine*>(c[maxkoef]);
    cout<<*temp;
}

using namespace std;
int main() {
    int test_case;

    cin >> test_case;

    //For CovidVaccine
    char manufacturer[100];
    char vaccineName[100];
    float basicEfficiencyCoefficient;

    //For GeneticVaccine
    unsigned short geneticMechanism; // 0 -> RNA, 1 -> DNA

    //For InactivatedVaccine
    unsigned short constituentIngredient; //0 -> DMG, 1 -> PEG, 2 -> SM_102, 3 -> DPSC


    if (test_case == 1) {
        // Test Case GeneticVaccine - Constructor, operator <<, calculateVaccineEfficiency
        cout << "Testing class GeneticVaccine, operator<< and calculateVaccineEfficiency" << endl;
        cin.get();
        cin.getline(manufacturer, 100);
        cin.getline(vaccineName, 100);
        cin >> basicEfficiencyCoefficient;
        cin >> geneticMechanism;

        GeneticVaccine gv(manufacturer, vaccineName, basicEfficiencyCoefficient, geneticMechanism);

        cout << gv;
    } else if (test_case == 2) {
        // Test Case InactivatedVaccine - Constructor, operator <<, calculateVaccineEfficiency
        cout << "Testing class InactivatedVaccine, operator<< and calculateVaccineEfficiency" << endl;
        cin.get();
        cin.getline(manufacturer, 100);
        cin.getline(vaccineName, 100);
        cin >> basicEfficiencyCoefficient;
        cin >> constituentIngredient;

        InactivatedVaccine iv(manufacturer, vaccineName, basicEfficiencyCoefficient, constituentIngredient);

        cout << iv;
    } else if (test_case == 3) {
        cout << "Testing operator <=" << endl;

        cin.get();
        cin.getline(manufacturer, 100);
        cin.getline(vaccineName, 100);
        cin >> basicEfficiencyCoefficient;
        cin >> geneticMechanism;

        GeneticVaccine gv(manufacturer, vaccineName, basicEfficiencyCoefficient, geneticMechanism);

        cin.get();
        cin.getline(manufacturer, 100);
        cin.getline(vaccineName, 100);
        cin >> basicEfficiencyCoefficient;
        cin >> constituentIngredient;

        InactivatedVaccine iv(manufacturer, vaccineName, basicEfficiencyCoefficient, constituentIngredient);

        if (gv <= iv) {
            cout << iv;
        } else {
            cout << gv;
        }
    } else if (test_case == 4) {
        cout << "Testing operator <=" << endl;

        cin.get();
        cin.getline(manufacturer, 100);
        cin.getline(vaccineName, 100);
        cin >> basicEfficiencyCoefficient;
        cin >> geneticMechanism;

        GeneticVaccine gv1(manufacturer, vaccineName, basicEfficiencyCoefficient, geneticMechanism);

        cin.get();
        cin.getline(manufacturer, 100);
        cin.getline(vaccineName, 100);
        cin >> basicEfficiencyCoefficient;
        cin >> geneticMechanism;

        GeneticVaccine gv2(manufacturer, vaccineName, basicEfficiencyCoefficient, geneticMechanism);

        if (gv1 <= gv2) {
            cout << gv2;
        } else {
            cout << gv1;
        }
    } else if (test_case == 5) {
        cout << "Testing function: mostEffectiveInactivatedVaccine " << endl;

        //1 - GeneticVaccine
        //2 - InactivatedVaccine
        short vaccineType;

        int number_of_vaccines;
        CovidVaccine **vaccine_array;

        cin >> number_of_vaccines;

        vaccine_array = new CovidVaccine *[number_of_vaccines];

        for (int i = 0; i < number_of_vaccines; ++i) {
            cin >> vaccineType;

            cin.get();
            cin.getline(manufacturer, 100);
            cin.getline(vaccineName, 100);
            cin >> basicEfficiencyCoefficient;

            switch (vaccineType) {
                case 1:
                    cin >> geneticMechanism;
                    vaccine_array[i] = new GeneticVaccine(manufacturer, vaccineName, basicEfficiencyCoefficient,
                                                          geneticMechanism);
                    break;
                case 2:
                    cin >> constituentIngredient;
                    vaccine_array[i] = new InactivatedVaccine(manufacturer, vaccineName, basicEfficiencyCoefficient,
                                                              constituentIngredient);
                    break;
            }

        }

        mostEffectiveInactivatedVaccine(vaccine_array, number_of_vaccines);
        delete[] vaccine_array;
    }

    return 0;
}
