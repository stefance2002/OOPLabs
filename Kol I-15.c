#include<stdio.h>

struct rabotnanedela
{
    int casovi[5];
    int broj;
};
typedef struct rabotnanedela rabotnanedela;

struct rabotnik
{
    char ime[50];
    rabotnanedela nedeli[4];
};
typedef struct rabotnik rabotnik;

void table(rabotnik *r, int n)
{
    int i, j, k, vkupno=0, total=0;
    printf("TABLE\nRab\t1\t2\t3\t4\tVkupno\n");
    for(i=0; i<n; i++)
    {
        total=0;
        printf("%s\t", r[i].ime);
        for(j=0; j<4; j++)
        {
            vkupno=0;
            for(k=0; k<5; k++)
            {
               vkupno+=r[i].nedeli[j].casovi[k];
            }
            printf("%d\t", vkupno);
            total+=vkupno;
        }
        printf("%d\n", total);
    }
}

int maxnedela(rabotnik *r, int n)
{
    int max=0, maxI=0, j, k, vkupno;
    for(j=0; j<4; j++)
    {
        vkupno=0;
        for(k=0; k<5; k++)
        {
            vkupno+=r[n/2].nedeli[j].casovi[k];
        }
        if(vkupno>max)
        {
            max=vkupno;
            maxI=j+1;
        }
    }
    return maxI;
}
int main()
{
    int n, i, j, k;
    scanf("%d", &n);
    rabotnik rabotnici[n];
    for(i=0; i<n; i++)
    {
        scanf("%s", rabotnici[i].ime);
        for(j=0; j<4; j++)
        {
            for(k=0; k<5; k++)
            {
                scanf("%d", &rabotnici[i].nedeli[j].casovi[k]);
            }
        }
    }
    table(rabotnici, n);
    printf("MAX NEDELA NA RABOTNIK: %s\n", rabotnici[n / 2].ime);
    printf("%d", maxnedela(&rabotnici[n / 2], n));

    return 0;
}
