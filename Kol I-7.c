#include<stdio.h>

struct vozenje
{
    char ime[100];
    int vreme;
    float cena;
    int popust;
};
typedef struct vozenje vozenje;
struct zabavenpark
{
    char ime[100];
    char lokacija[100];
    vozenje niza[100];
    int n;
};
typedef struct zabavenpark zabavenpark;

void print(zabavenpark *p, int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%s %s\n", p[i].ime, p[i].lokacija);

        for(int j=0; j<p[i].n; j++)
        {
            printf("%s %d %.2f\n", p[i].niza[j].ime, p[i].niza[j].vreme, p[i].niza[j].cena);
        }
    }
}

void najdobar(zabavenpark *p, int n)
{
    int maxtraenje=0, maxV=0,max=0;

    for(int i=0;i<n;i++)
    {
        int count=0;
        int vreme=0;
        for(int j=0;j<p[i].n;j++)
        {
            if(p[i].niza[j].popust==1)
                count++;
            vreme+= p[i].niza[j].vreme;
        }
        if(count>maxV)
        {
            maxV = count;
            max = i;
            maxtraenje = vreme;
        }
        else if(count==maxV&&vreme>maxtraenje)
        {
            max = i;
            maxtraenje = vreme;
        }
    }
    printf("Najdobar park: %s %s\n",p[max].ime,p[max].lokacija);
}

int main()
{
    int n;
    scanf("%d", &n);
    zabavenpark array[100];
    for(int i=0; i<n; i++)
    {
        scanf("%s%s%d", array[i].ime, array[i].lokacija, &array[i].n);

        for(int j=0; j<array[i].n; j++)
        {
            scanf("%s", array[i].niza[j].ime);
            scanf("%d", &array[i].niza[j].vreme);
            scanf("%f", &array[i].niza[j].cena);
            scanf("%d", &array[i].niza[j].popust);
        }
    }
    print(array, n);
    najdobar(array, n);
    return 0;
}
