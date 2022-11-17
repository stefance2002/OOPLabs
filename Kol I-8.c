#include<stdio.h>

struct laptop
{
    char firma[100];
    float inch;
    int touch;
    int cena;
};
typedef struct laptop laptop;

struct itstore
{
    char ime[100];
    char lokacija[100];
    int a;
    laptop niza[100];
};
typedef struct itstore itstore;

void print(itstore *p, int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%s %s\n", p[i].ime, p[i].lokacija);
        for(int j=0; j<p[i].a; j++)
        {
            printf("%s ", p[i].niza[j].firma);
            printf("%.1f ", p[i].niza[j].inch);
            printf("%d\n", p[i].niza[j].cena);
        }
    }
}

void najeftina(itstore *p, int n)
{
    int i, j, maxcena=10000000000000, maxI=0;
    for(i=0; i<n; i++)
    {
        for(j=0; j<p[i].a; j++)
        {
            if((p[i].niza[j].cena<maxcena) && (p[i].niza[j].touch))
            {
                maxcena=p[i].niza[j].cena;
                maxI=i;
            }
        }
    }
    printf("Najeftina ponuda ima prodavnicata:\n%s %s\n", p[maxI].ime, p[maxI].lokacija);
    printf("Najniskata cena iznesuva: %d", maxcena);
}

int main()
{
    itstore s[100];
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        scanf("%s%s%d", s[i].ime, s[i].lokacija, &s[i].a);
        for(int j=0; j<s[i].a; j++)
        {
            scanf("%s", s[i].niza[j].firma);
            scanf("%f", &s[i].niza[j].inch);
            scanf("%d", &s[i].niza[j].touch);
            scanf("%d", &s[i].niza[j].cena);
        }
    }
    print(s, n);
    najeftina(s, n);

    return 0;
}
