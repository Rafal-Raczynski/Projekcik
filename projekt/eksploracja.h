#ifndef eksploracja_h
#define eksploracja_h

#include <stdio.h>
#include <stdlib.h>
#include"cjsonik.h"

typedef struct Mapka
{
    char mapa[20][20];
    stan*gra;
    stanex*graex;
};

#endif