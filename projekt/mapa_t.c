#include "mapa.h"

int main(int argc, char **argv)
{
   mapka *m;
   m=ustawienie_poczatkowe(m);
   wypisz(m);
   m=nowa_macierz_dol(m);
   wypisz(m);
   m=nowa_macierz_lewo(m);
   wypisz(m);
   m=nowa_macierz_prawo(m);
   wypisz(m);
   zwolnij(m);
   return 0;
}