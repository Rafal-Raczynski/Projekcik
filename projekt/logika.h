#ifndef logika_h
#define logika_h

#include"mapa.h"

typedef struct Logika
{
    stan* gra;
    stanex* graex;
    mapka* swiat;

}logika;


logika* poczatek(char*token);
char tlumacz_teren(char *teren);
int rusz_do_gory(logika* g, char* token);
int rusz_w_lewo(logika* g, char* token);
int rusz_w_prawo(logika* g, char* token);
int rusz_do_dolu(logika* g, char* token);
mapka* nowa_macierz(logika*m);
int interpretuj_wspolrzedna_x(logika*a);
int interpretuj_wspolrzedna_y(logika*a);
void uzupelnij(logika*x);
int czy_pole_jest_na_krancu(logika* m);
void eksploruj(logika*g, char* token);
int interpretuj_wspolrzedna_x_ex(logika*a,int i);
int interpretuj_wspolrzedna_y_ex(logika*a,int i);
void uzupelnijex(logika* m);


#endif
