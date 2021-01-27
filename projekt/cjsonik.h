#ifndef cjsonik_h
#define cjsonik_h

#include <stdio.h>
#include <stdlib.h>
#include "../../cJSON/cJSON.h"
#include "komunikacja.h"

typedef struct stan_gry
{
    int current_x;
    int current_y;
    char* current_session;
    char* direction;
    int step;
    char*field_type;
    char*field_bonus;
}stan;

typedef struct stan_gryex
{
    int x[3];
    int y[3];
    char *type[3];
}stanex;

stan* stan_gry(const char * const swiat);

stanex* stan_gry_ex(const char * const swiat);

void zwolnij_stan(stan* x);

void zwolnij_stan_ex(stanex* x);

#endif