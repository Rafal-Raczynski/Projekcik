#ifndef cjsonik_h
#define cjsonik_h


#include <stdio.h>
#include <stdlib.h>
#include "../cJSON/cJSON.h"
#include "komunikacja.h"

typedef struct Plansza
{
    char tab[10][10];
   // char powierzchnia;
}plansza;

plansza stan_gry(const char * const swiat);
void wypisz_macierz(plansza xd);

#endif