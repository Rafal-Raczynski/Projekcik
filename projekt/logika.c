#include "logika.h"

logika* poczatek(char*token)
{
    char buffer[2048];
    logika* wizualizacja=(logika*) malloc(sizeof(logika));
    wizualizacja->swiat=ustawienie_poczatkowe(wizualizacja->swiat);
    wypisz(wizualizacja->swiat);
    info(token);
    FILE *f = fopen("odp.json", "r+");
    fread(buffer,1,2048,f);
    wizualizacja->gra=stan_gry(buffer);
    wizualizacja->swiat->poczatkowy_x=wizualizacja->gra->current_x;
    wizualizacja->swiat->poczatkowy_y=wizualizacja->gra->current_y;
    uzupelnij(wizualizacja);
    wypisz(wizualizacja->swiat);
    wypisztxt("mapa.txt",wizualizacja->swiat);

    return wizualizacja;
}

//logika* kontynuacja(char*token)
//{
//  char buffer[2048];
//  logika* wizualizacja=(logika*) malloc(sizeof(logika));
//  wizualizacja->swiat;
//  wczytaj("mapa.txt",g->swiat);
//  info(token);
//  FILE *f = fopen("odp.json", "r+");
//  fread(buffer,1,2048,f);
//  wizualizacja->gra=stan_gry(buffer);
//  wizualizacja->swiat->poczatkowy_x=wizualizacja->gra->current_x;
//  wizualizacja->swiat->poczatkowy_y=wizualizacja->gra->current_y; 
//
//}

void wczytaj_zapisz(logika *g)
{   
    
    char buffer[2048];
    wczytaj("mapa.txt",g->swiat);
    FILE *f = fopen("odp.json", "r+");
    fread(buffer,1,2048,f);
    g->gra=stan_gry(buffer);
    uzupelnij(g);
    fclose(f);
    wypisztxt("mapa.txt", g->swiat);
    wypisz(g->swiat);
}

void wczytaj_zapiszex(logika *g)
{   
    
    char buffer[2048];
    wczytaj("mapa.txt",g->swiat);
    FILE *f = fopen("odp.json", "r+");
    fread(buffer,1,2048,f);
    g->graex=stan_gry_ex(buffer);
    uzupelnijex(g);
    fclose(f);
    wypisztxt("mapa.txt", g->swiat);
    wypisz(g->swiat);
}

char tlumacz_teren(char *teren) {
    
    if (strcmp(teren,"grass")==0)
        return 'g';
    else if (strcmp(teren,"sand")==0)
        return 's';
    else if (strcmp(teren,"wall")==0)
        return 'w';
    else printf("problem tłumaczenia terenu");  
}

void eksploruj(logika*g, char* token)
{
  explore(token);
  wczytaj_zapiszex(g);
}

int rusz_do_gory(logika* g, char* token)
{ 
  int x=g->gra->current_y;
    if(strcmp(g->gra->direction,"N")!=0)
    {
        while(strcmp(g->gra->direction,"N")!=0)
        {
            rotate_right(token);
            wczytaj_zapisz(g);
        }
    }
    move(token);
    wczytaj_zapisz(g);
  if(x==g->gra->current_y)
  {
  g->swiat->mapa[interpretuj_wspolrzedna_y(g)+1][interpretuj_wspolrzedna_x(g)]='w';
  wypisztxt("mapa.txt", g->swiat);
  wypisz(g->swiat);
  
  return 1;
  }
  return 0;
}

void uzupelnij(logika*x)
{ 
    if(czy_pole_jest_na_krancu(x)==1)
    {
        x->swiat=nowa_macierz(x);
    }
    x->swiat->mapa[interpretuj_wspolrzedna_y(x)][interpretuj_wspolrzedna_x(x)]=tlumacz_teren(x->gra->field_type);
}

mapka* nowa_macierz(logika*m)
{
    
  if(interpretuj_wspolrzedna_x(m)==0)
  {
    m->swiat=nowa_macierz_lewo(m->swiat);
    return m->swiat;
  }
  
  if(interpretuj_wspolrzedna_y(m)==0)
  {
    m->swiat=nowa_macierz_dol(m->swiat);
    return m->swiat;
  }
  
   if(interpretuj_wspolrzedna_y(m)==m->swiat->wiersze-1)
  {
    m->swiat=nowa_macierz_gora(m->swiat);
    return m->swiat;
  }


    if(interpretuj_wspolrzedna_x(m)==m->swiat->kolumny-1)
  {
    m->swiat=nowa_macierz_prawo(m->swiat);
    return m->swiat;
  }
}

int rusz_w_prawo(logika* g, char* token)
{
    int x=g->gra->current_x;
  if(strcmp(g->gra->direction,"E")!=0)
  {
      while(strcmp(g->gra->direction,"E")!=0)
      {
          rotate_right(token);
          wczytaj_zapisz(g);
      }
  }
  move(token);
  wczytaj_zapisz(g);
  if(x==g->gra->current_x)
  {
  g->swiat->mapa[interpretuj_wspolrzedna_y(g)][interpretuj_wspolrzedna_x(g)+1]='w';
  wypisztxt("mapa.txt", g->swiat);
  wypisz(g->swiat);
  
  return 1;
  }
  return 0;
  
}

int rusz_w_lewo(logika* g, char* token)
{
  int x=g->gra->current_x;
    if(strcmp(g->gra->direction,"W")!=0)
    {
        while(strcmp(g->gra->direction,"W")!=0)
        {
            rotate_right(token);
            wczytaj_zapisz(g);
        }
    }
    move(token);
    wczytaj_zapisz(g);
  if(x==g->gra->current_x)
  {
  g->swiat->mapa[interpretuj_wspolrzedna_y(g)][interpretuj_wspolrzedna_x(g)-1]='w';
  wypisztxt("mapa.txt", g->swiat);
  wypisz(g->swiat);
  return 1;
  }
  return 0;


}

int rusz_do_dolu(logika* g, char* token)
{
  int x=g->gra->current_y;
  if(strcmp(g->gra->direction,"S")!=0)
  {
      while(strcmp(g->gra->direction,"S")!=0)
      {
          rotate_right(token);
          wczytaj_zapisz(g);
      }
  }
  move(token);
  wczytaj_zapisz(g);
  if(x==g->gra->current_y)
  {
  g->swiat->mapa[interpretuj_wspolrzedna_y(g)-1][interpretuj_wspolrzedna_x(g)]='w';
  wypisztxt("mapa.txt", g->swiat);
  wypisz(g->swiat);
  
  return 1;
  }
  return 0;
  
}

int interpretuj_wspolrzedna_x(logika*a)
{
  int x=(a->gra->current_x)-(a->swiat->poczatkowy_x)+(a->swiat->p);
  return x;
}

int interpretuj_wspolrzedna_y(logika*a)
{
    int y=(a->gra->current_y)-(a->swiat->poczatkowy_y)+(a->swiat->q);
    return y;
}

int interpretuj_wspolrzedna_x_ex(logika*a,int i)
{
  int x=(a->graex->x[i])-(a->swiat->poczatkowy_x)+(a->swiat->p);
  return x;
}

int interpretuj_wspolrzedna_y_ex(logika*a,int i)
{
    int y=(a->graex->y[i])-(a->swiat->poczatkowy_y)+(a->swiat->q);
    return y;
}

int czy_pole_jest_na_krancu(logika* m)
{
    if(interpretuj_wspolrzedna_x(m)==0 || interpretuj_wspolrzedna_y(m)==0 || interpretuj_wspolrzedna_y(m)==m->swiat->wiersze-1 || interpretuj_wspolrzedna_x(m)==m->swiat->kolumny-1 )
    return 1;
    return 0;
}

void uzupelnijex(logika* m)
{
    for (int i = 0; i < 3; i++) 
        m->swiat->mapa[interpretuj_wspolrzedna_y_ex(m,i)][interpretuj_wspolrzedna_x_ex(m,i)]= tlumacz_teren(m->graex->type[i]);
}