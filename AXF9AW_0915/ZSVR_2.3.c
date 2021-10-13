#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main()
{

    FILE *fp, *fpp;


    char ch;

    char nev1[50];
    char nev2[50] = "masolt.txt";


    printf("Kerem a fajl nevet: ");
    scanf("%s", nev1);

    fp = fopen(nev1, "w");
    printf("Kerem az uzenetet: ");

    while( (ch = getchar()) != '#') {
        putc(ch, fp);
    }

    fclose(fp);

    int pos;


    if ((fp = fopen(nev1, "r")) == NULL)
    {
        printf("\nHiba a fajl megnyitasa soran!\n");
        return 0;
    }


    else
    {
        printf("\nFajl megnyitva masolasra\n ");
    }

    fpp = fopen(nev2, "w");
    fseek(fp, 0L, SEEK_END);
    pos = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    while (pos--)
    {
        ch = fgetc(fp);
        fputc(ch, fpp);
    }

    fclose(fp);
    fclose(fpp);
}
