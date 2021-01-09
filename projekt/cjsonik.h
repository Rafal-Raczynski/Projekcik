#ifndef cjsonik_h
#define cjsonik_h


#include <stdio.h>
#include <stdlib.h>
#include "../../cJSON/cJSON.h"
#include "komunikacja.h"

typedef struct stan_gry
{
    char*name;
    int current_x;
    int current_y;
    char* current_session;
    char*direction;
    int step;
    char*field_type;
    char*field_bonus;
}stan;
typedef struct stan_gryex
{
int x1,x2,x3,y1,y2,y3;
char*type1;
char*type2;
char*type3;
}stanex;

stan* stan_gry(const char * const swiat);
stanex* stan_gry_ex(const char * const swiat);
//void wypisz_macierz(plansza xd);

#endif