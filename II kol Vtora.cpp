#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;

class WrongLabelsFormatException
{
public:
    void pecati()
    {
        cout<<"Labels must have the same length";
    }
};

class Evaluator
{
protected:
    char vistinski[100], predvideni[100];
public:
    Evaluator(const char*v="", const char*p="")
    {
        if(strlen(v)!=strlen(p))
        {
            throw WrongLabelsFormatException();
        }
        strcpy(vistinski, v);
        strcpy(predvideni, p);
    }
    virtual double evaluate()=0;
    virtual void print()=0;
    bool operator>=(Evaluator&d)
    {
        return (evaluate()>=d.evaluate());
    }
};

class AccuracyEvaluator : public Evaluator
{
private:

public:
    AccuracyEvaluator(const char*v="", const char*p=""):Evaluator(v, p)
    {
        if(strlen(v)!=strlen(p))
        {
            throw WrongLabelsFormatException();
        }
        strcpy(vistinski, v);
        strcpy(predvideni, p);
    }
    double evaluate()
    {
        int tocni=0, vkupno=0;
        for(int i=0; i<strlen(vistinski); i++)
        {
            char a=vistinski[i];
            char b=predvideni[i];
            if(b==a)
            {
                vkupno++;
                tocni++;
            }
            else
            {
                vkupno++;
            }
            }
        return (double)tocni/vkupno;
    }
    void print()
    {
        cout<<"Number of data points: "<<strlen(vistinski)<<" Prediction Accuracy: "<<evaluate()<<endl;
    }

};

class SensitivityEvaluator : public Evaluator
{
private:

public:
    SensitivityEvaluator(const char*v="", const char*p=""):Evaluator(v, p)
    {
        if(strlen(v)!=strlen(p))
        {
            throw WrongLabelsFormatException();
        }
        strcpy(vistinski, v);
        strcpy(predvideni, p);
    }
    double evaluate()
    {
        int tocni=0, vkupno=0;
        char a='+';
        for(int i=0; i<strlen(vistinski); i++)
        {
            char b=vistinski[i];
            if(b==a)
            {
                char c=predvideni[i];
                if(b==c)
                {
                    tocni++;
                    vkupno++;
                }
                else
                {
                    vkupno++;
                }
            }
        }
        return (double)tocni/vkupno;
    }
    void print()
    {
        cout<<"Number of data points: "<<strlen(vistinski)<<" Prediction Sensitivity: "<<evaluate()<<endl;
    }
};

Evaluator * highestScore (Evaluator ** evaluators, int n)
{
    int najgolem=0;
    for(int i=0; i<n; i++)
    {
        if(evaluators[i]->evaluate()>=evaluators[najgolem]->evaluate())
        {
            najgolem=i;
        }
    }
    return evaluators[najgolem];
}

int main() {
    int testCase;
    char trueLabels[100];
    char predictedLabels[100];
    cin >> testCase;
    if (testCase == 1) {
        cout << "TESTING CREATION OF ACCURACY EVALUATOR. EXCEPTION CAN HAPPEN HERE!" << endl;
        cin >> trueLabels >> predictedLabels;

        try
        {
            Evaluator *evaluator = new AccuracyEvaluator(trueLabels, predictedLabels);
            cout << evaluator->evaluate() << endl;
            evaluator->print();
        }
        catch(WrongLabelsFormatException&e)
        {
            e.pecati();
        }


    } else if (testCase == 2) {
        cout << "TESTING CREATION OF ACCURACY EVALUATOR. EXCEPTION CAN HAPPEN HERE!" << endl;
        cin >> trueLabels >> predictedLabels;
         try
        {
            Evaluator *evaluator = new SensitivityEvaluator(trueLabels, predictedLabels);
            cout << evaluator->evaluate() << endl;
            evaluator->print();
        }
        catch(WrongLabelsFormatException&e)
        {
            e.pecati();
        }


    } else if (testCase == 3) {
        cout << "TESTING CREATION OF BOTH EVALUATORS. EXCEPTION CAN HAPPEN HERE!" << endl;
        cin >> trueLabels >> predictedLabels;
        try
        {
            Evaluator *accuracy = new AccuracyEvaluator(trueLabels, predictedLabels);
            Evaluator *sensitivity = new SensitivityEvaluator(trueLabels, predictedLabels);
            accuracy->print();
            sensitivity->print();
        }
        catch(WrongLabelsFormatException&e)
        {
            e.pecati();
        }


    } else if (testCase == 4) {
        cout << "TESTING OPERATOR >=" << endl;
        cin >> trueLabels >> predictedLabels;
        Evaluator *accuracy = new AccuracyEvaluator(trueLabels, predictedLabels);
        Evaluator *sensitivity = new SensitivityEvaluator(trueLabels, predictedLabels);
        cin >> trueLabels >> predictedLabels;
        Evaluator *accuracy1 = new AccuracyEvaluator(trueLabels, predictedLabels);
        Evaluator *sensitivity1 = new SensitivityEvaluator(trueLabels, predictedLabels);

        accuracy->print();
        cout << (((*accuracy) >= (*sensitivity)) ? ">=" : "<") << endl;
        sensitivity->print();
        cout << endl;

        sensitivity->print();
        cout << (((*sensitivity) >= (*accuracy)) ? ">=" : "<") << endl;
        accuracy->print();
        cout << endl;

        accuracy->print();
        cout << (((*accuracy) >= (*accuracy1)) ? ">=" : "<") << endl;
        accuracy1->print();
        cout << endl;

        sensitivity->print();
        cout << (((*sensitivity) >= (*sensitivity1)) ? ">=" : "<") << endl;
        sensitivity1->print();
        cout << endl;
    } else {
        cout << "INTEGRATION TEST AND TESTING GLOBAL FUNCTION. EXCEPTION CAN HAPPEN HERE!" << endl;
        int n;
        cin >> n;
        Evaluator **evaluators = new Evaluator *[n];
        for (int i = 0; i < n; i++) {
            int type;
            cin >> type;
            cin >> trueLabels >> predictedLabels;
            try
            {
            if (type == 1) { //accuracy
                evaluators[i] = new AccuracyEvaluator(trueLabels, predictedLabels);
            } else { //sensitivity
                evaluators[i] = new SensitivityEvaluator(trueLabels, predictedLabels);
            }
            }
            catch(WrongLabelsFormatException&e)
            {
                e.pecati();
                i--;
                n--;
            }
        }

        cout << "PRINT ALL EVALUATORS FIRST!" << endl;
        for (int i = 0; i < n; i++) {
            evaluators[i]->print();
        }

        cout << "RESULT FROM HIGHEST SCORE METHOD" << endl;
        highestScore(evaluators, n)->print();
    }

}
