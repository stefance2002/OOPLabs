#include <stdio.h>
typedef struct proizvod
{
    char ime[50];
    float cena, kol;
}proizvod;

int main()
{
    int n;
    scanf("%d", &n);
    proizvod brproizvodi[n];
    float total=0;

    for(int i=0; i<n; i++)
    {
        scanf("%s%f%f", &brproizvodi[i].ime, &brproizvodi[i].cena, &brproizvodi[i].kol);
        total+=brproizvodi[i].cena*brproizvodi[i].kol;
        printf("%d. %s\t%.2f x %.1f = %.2f\n", i+1, brproizvodi[i].ime, brproizvodi[i].cena, brproizvodi[i].kol, brproizvodi[i].cena*brproizvodi[i].kol);
    }
    printf("Total: %.2f", total);
    return
     0;
}
