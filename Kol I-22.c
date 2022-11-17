#include <stdio.h>
#include <string.h>
struct proizvod
{
    char kod[20];
    int cena;
    int dostapni;
};
typedef struct proizvod proizvod;

struct naracka
{
    char ime[15];
    proizvod proizvodi[10];
    int naracani[10];
    int n;
};
typedef struct naracka naracka;

void pecatifaktura(naracka *n)
{
    int i, total=0;
    printf("Faktura za %s\n", n[0].ime);

    for(int j=0; j<n[0].n; j++)
    {
        if(n[0].proizvodi[j].dostapni<n[0].naracani[j])
        {
            printf("Fakturata ne moze da se izgotvi");
            return ;
        }
    }
    for(i=0;i<n[0].n; i++)
    {
         int m=i;
         if(strcmp(n[0].proizvodi[i].kod, n[0].proizvodi[i+1].kod) > 0)
         {
            char tmp[20];
            strcpy(tmp,n[0].proizvodi[i].kod);
            strcpy(n[0].proizvodi[i].kod, n[0].proizvodi[i+1].kod);
            strcpy(n[0].proizvodi[i+1].kod, tmp);
            int temp=n[0].proizvodi[i].cena;
            n[0].proizvodi[i].cena=n[0].proizvodi[i+1].cena;
            n[0].proizvodi[i+1].cena=temp;
        }
    }
    for(i=0; i<2; i++)
    {
        printf("%s ", n[0].proizvodi[i].kod);
        printf("%d ", n[0].proizvodi[i].cena);
        printf("%d ", n[0].naracani[i]);
        printf("%d\n", n[0].naracani[i]*n[0].proizvodi[i].cena);
        total+=(n[0].naracani[i]*n[0].proizvodi[i].cena);
    }
    for(i=3; i<(n[0].n+1); i++)
    {
        printf("%s ", n[0].proizvodi[i].kod);
        printf("%d ", n[0].proizvodi[i].cena);
        printf("%d ", n[0].naracani[i-1]);
        printf("%d\n", n[0].naracani[i-1]*n[0].proizvodi[i].cena);
        total+=(n[0].naracani[i-1]*n[0].proizvodi[i].cena);
    }
    printf("Vkupnata suma na fakturata e %d", total);
}

int main()
{
    int i;
    naracka Naracka[1];
    scanf("%s%d", Naracka[0].ime, &Naracka[0].n);

    for(i=0; i<Naracka[0].n; i++)
    {
        scanf("%s", Naracka[0].proizvodi[i].kod);
        scanf("%d", &Naracka[0].proizvodi[i].cena);
        scanf("%d", &Naracka[0].proizvodi[i].dostapni);
    }
    for(i=0; i<Naracka[0].n; i++)
    {
        scanf("%d", &Naracka[0].naracani[i]);
    }
    pecatifaktura(Naracka);
    return 0;
}
