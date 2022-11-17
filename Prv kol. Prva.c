#include<stdio.h>

struct Recovery
{
    int den;
    int mesec;
    int godina;
};
typedef struct Recovery Recovery;

struct CovidPatient
{
    char ime[50];
    char embg[13];
    int vakciniran;
    Recovery datum;
};
typedef struct CovidPatient CovidPatient;

void vakcinirani(CovidPatient *p, int broj)
{
    int brojac=0;
    for(int i=0; i<broj; i++)
    {
        if(p[i].vakciniran)
        {
            brojac++;
        }
    }
    float procent;
    procent=(float)brojac/broj*100;
    printf("Procentualno %.2f%% od kovid pacientite imale primeno vakcina", procent);
}
int checkmonth(CovidPatient *p, int i, int d, int m, int g)
{
    if(p[i].datum.godina==g && (m-p[i].datum.mesec>6 ||p[i].datum.mesec-m>6))
    {
        return 1;
    }
    else if(p[i].datum.godina-g>1 || g-p[i].datum.godina-g>1)
    {
        return 1;
    }
    return 0;
}
void pcrtest(CovidPatient *p, int broj, int d, int m, int g)
{
    int k;
    printf("Pacienti koi treba da pravat PCR test na %d/%d/%d se:\n", d, m, g);
    for(int i=1; i<broj; i++)
    {
        k=checkmonth(p, i, d, m, g);
        if(p[i].vakciniran==0 && k)
        {
            printf("Ime: %s - embg: %s - vakciniran(1/0): %d\n", p[i].ime, p[i].embg, p[i].vakciniran);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    CovidPatient pacienti[100];
    for(int i=0; i<n; i++)
    {
        scanf("%s%s", pacienti[i].ime, pacienti[i].embg);
        scanf("%d/%d/%d", &pacienti[i].datum.den, &pacienti[i].datum.mesec, &pacienti[i].datum.godina);
        scanf("%d", &pacienti[i].vakciniran);
    }
    int den, mesec, godina;
    scanf("%d/%d/%d", &den, &mesec, &godina);

    pcrtest(pacienti, n, den, mesec, godina);
    vakcinirani(pacienti, n);

    return 0;
}
