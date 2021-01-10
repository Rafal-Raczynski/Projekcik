#ifndef eksploracja_h
#define eksploracja_h

#include <stdio.h>
#include <stdlib.h>
#include"cjsonik.h"
#define N 20
typedef struct Mapka
{
    char mapa[N][N];
    stan*gra;
    stanex*graex;
}mapka;

void wypisz(mapka* x);
void wypisztxt(char*fnazwa,mapka* x);
void wczytaj(char*fnazwa,mapka*x);
void ustawienie_poczatkowe(mapka *x);
void uzupelnij(mapka*x);
void uzupelnijex(mapka*x);

#endif