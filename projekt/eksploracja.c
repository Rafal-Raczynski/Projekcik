
#include "eksploracja.h"

void wypisz(mapka* x)
{
    int i, j;
    printf("[ ");
    for (i = N-1; i >= 0; i--)
    {
        for (j=0; j < N; j++) 
        {
        printf("%c ", x->mapa[i][j]);
        }
        if (i > 1)
        printf("\n  ");
    }
    printf("]\n");
}

void wypisztxt(char*fnazwa,mapka* x)
{
    int i, j;
    FILE*fin=fopen(fnazwa,"w+");
    for (i = N-1; i >= 0; i--)
    {
        for (j=0; j <N; j++) 
        {
        fprintf(fin,"%c",x->mapa[i][j]);
        }
        fprintf(fin,"\n");
    }
    fclose(fin);
}

void wczytaj(char*fnazwa,mapka*x)
{
 FILE*fin=fopen(fnazwa,"r+");
for (int i=N-1; i >= 0; i--) {
    for (int j=0; j < N; j++) {

        fscanf(fin, "%c ", &x->mapa[i][j]);
    }
}
 fclose(fin);
}

void ustawienie_poczatkowe(mapka *x)
{
    for(int i=N;i>0;i--)
        for(int j=0; j<N;j++)
        x->mapa[i][j]='.';

}   

void uzupelnij(mapka*x)
{
    if(strcmp(x->gra->field_type,"grass")==0)
    x->mapa[x->gra->current_y][x->gra->current_x]='g';
    else
    x->mapa[x->gra->current_y][x->gra->current_x]='s';
}

//void uzupelnijex(mapka*x)
//{
//    
//}