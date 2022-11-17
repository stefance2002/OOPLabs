#include<stdio.h>

struct skilift
{
    char ime[15];
    int korisnici;
    int pusten;
};
typedef struct skilift skilift;

struct skicentar
{
    char ime[20];
    char lokacija[20];
    skilift liftovi[20];
    int n;
};
typedef struct skicentar skicentar;

void kapacitet(skicentar *p, int n)
{
    int i, j, vkupen, maxvkupen=0, maxI=0, pusteni, maxpusteni=0;
    for(i=0; i<n; i++)
    {
        vkupen=0;
        pusteni=0;
        for(j=0; j<p[i].n; j++)
        {
            if(p[i].liftovi[j].pusten)
            {
                vkupen+=p[i].liftovi[j].korisnici;
                pusteni++;
            }
        }
        if(vkupen>maxvkupen)
        {
            maxvkupen=vkupen;
            maxI=i;
            maxpusteni=pusteni;
        }
        else if(vkupen==maxvkupen)
        {
            if(pusteni>maxpusteni)
            {
                maxvkupen=vkupen;
                maxI=i;
                maxpusteni=pusteni;
            }
        }
    }
    printf("%s\n%s\n%d", p[maxI].ime, p[maxI].lokacija, maxvkupen);
}

int main()
{
    int n, i, j;
    scanf("%d", &n);
    skicentar centari[n];

    for(i=0; i<n; i++)
    {
        scanf("%s%s%d", centari[i].ime, centari[i].lokacija, &centari[i].n);
        for(j=0; j<centari[i].n; j++)
        {
            scanf("%s", centari[i].liftovi[j].ime);
            scanf("%d", &centari[i].liftovi[j].korisnici);
            scanf("%d", &centari[i].liftovi[j].pusten);
        }
    }
    kapacitet(centari, n);

  return 0;
}
