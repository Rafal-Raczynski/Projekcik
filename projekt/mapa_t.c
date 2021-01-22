#include <stdio.h>
#include <stdlib.h>
#include "komunikacja.h"
#include "cjsonik.h"
#include "mapa.h"


int main(int argc, char **argv)
{
   mapka *m=(mapka*)malloc(sizeof(mapka));
   ustawienie_poczatkowe(m);
   wypisz(m);
   m=nowa_macierz(m);
   wypisz(m);
   //m=nowa_macierz_lewo(m);
   //wypisz(m);
   //m=nowa_macierz_prawo(m);
   //wypisz(m);
   return 0;
}