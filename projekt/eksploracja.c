
#include "eksploracja.h"

void wypisz(mapka* x)
{
    int i, j;
    
    for (i = N-1; i >= 0; i--)
    {
        for (j=0; j < N; j++) 
        {
        printf("%c ", x->mapa[i][j]);
        }
        
        printf("\n");
    }
    
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
    for(int i=N-1;i>=0;i--)
    {
        for(int j=0; j<N;j++)
        x->mapa[i][j]='.';

    }

}   

void uzupelnij(mapka*x)
{
    if(strcmp(x->gra->field_type,"grass")==0)
    x->mapa[x->gra->current_y][x->gra->current_x]='g';
    else
    x->mapa[x->gra->current_y][x->gra->current_x]='s';
}


void uzupelnijex(mapka*x)
{
    if(strcmp(x->graex->type1,"grass")==0)
    {
        x->mapa[x->graex->y1][x->graex->x1]='g';
    }
    else if (strcmp(x->graex->type1,"sand")==0)
    {
        x->mapa[x->graex->y1][x->graex->x1]='s';
    }
    else if (strcmp(x->graex->type1,"wall")==0)
    {
        x->mapa[x->graex->y1][x->graex->x1]='w';
    }

    if(strcmp(x->graex->type2,"grass")==0)
    {
        x->mapa[x->graex->y2][x->graex->x2]='g';
    }
    else if (strcmp(x->graex->type2,"sand")==0)
    {
        x->mapa[x->graex->y2][x->graex->x2]='s';
    }
    else if (strcmp(x->graex->type2,"wall")==0)
    {
        x->mapa[x->graex->y2][x->graex->x2]='w';
    }

    if(strcmp(x->graex->type3,"grass")==0)
    {
        x->mapa[x->graex->y3][x->graex->x3]='g';
    }
    else if (strcmp(x->graex->type3,"sand")==0)
    {
        x->mapa[x->graex->y3][x->graex->x3]='s';
    }
    else if (strcmp(x->graex->type3,"wall")==0)
    {
        x->mapa[x->graex->y3][x->graex->x3]='w';
    }



}




