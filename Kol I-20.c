#include<stdio.h>

struct pacient
{
    char ime[100];
    int osiguran;
    int pregledi;
};
typedef struct pacient pacient;

struct maticen
{
    char ime[100];
    int br;
    pacient pacienti[200];
    float cena;
};
typedef struct maticen maticen;

void najuspesen(maticen *p, int n)
{
    int i, j,  maxI=0, pregledi=0, maxpregledi=0;
    float zarabot=0, maxzarabot=0;
    for(i=0; i<n; i++)
    {
        zarabot=0;
        pregledi=0;
        for(j=0; j<p[i].br; j++)
        {
            if(p[i].pacienti[j].osiguran==0)
            {
                zarabot+=(p[i].pacienti[j].pregledi*p[i].cena);
                pregledi+=p[i].pacienti[j].pregledi;
            }
            else
            {
               pregledi+=p[i].pacienti[j].pregledi;
            }
        }
        if(zarabot>maxzarabot)
        {
            maxzarabot=zarabot;
            maxI=i;
            maxpregledi=pregledi;
        }
        if(zarabot==maxzarabot)
        {
            if(pregledi>maxpregledi)
            {
                maxzarabot=zarabot;
                maxI=i;
                maxpregledi=pregledi;
            }
        }
    }
    printf("%s %.2f %d", p[maxI].ime, maxzarabot, maxpregledi);
}

int main()
{
    int n, i, j;
    scanf("%d", &n);
    maticen doktori[n];

    for(i=0; i<n; i++)
    {
        scanf("%s%d%f", doktori[i].ime, &doktori[i].br, &doktori[i].cena);
        for(j=0; j<doktori[i].br; j++)
        {
            scanf("%s", doktori[i].pacienti[j].ime);
            scanf("%d", &doktori[i].pacienti[j].osiguran);
            scanf("%d", &doktori[i].pacienti[j].pregledi);
        }
    }
    najuspesen(doktori, n);

    return 0;
}
