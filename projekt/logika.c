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
  fclose(f);
  wizualizacja->swiat->poczatkowy_x=wizualizacja->gra->current_x;
  wizualizacja->swiat->poczatkowy_y=wizualizacja->gra->current_y;
  wizualizacja->graex=(stanex*) malloc(sizeof(stanex));
  for(int i=0;i<3;i++)
  {
    wizualizacja->graex->type[i] = (char*) malloc(sizeof(char));
  }
  uzupelnij(wizualizacja);
  wypisztxt("mapa.txt",wizualizacja->swiat);
  return wizualizacja;
}

void wczytaj_zapisz(logika *g)
{   
    
  char buffer[2048];
  wczytaj("mapa.txt",g->swiat);
  FILE *f = fopen("odp.json", "r+");
  fread(buffer,1,2048,f);
  zwolnij_stan(g->gra);
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
  zwolnij_stan_ex(g->graex);
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

int rusz_naprzod(logika*g,char*token)
{
  int x;
 if(strcmp(g->gra->direction,"N")==0)
  x=rusz_do_gory(g,token);
 else if(strcmp(g->gra->direction,"S")==0)
  x=rusz_do_dolu(g,token);
 else if(strcmp(g->gra->direction,"E")==0)
  x=rusz_w_prawo(g,token);
 else if(strcmp(g->gra->direction,"W")==0)
  x=rusz_w_lewo(g,token);
 
 return x;
}

void idz_do_sciany(logika*m,char*token)
{
  eksploruj(m,token);
  while(rusz_naprzod(m,token)!=1)
  {
    eksploruj(m,token);
  }
  
 rotate_right(token);
 wczytaj_zapisz(m);
 
}

void idz_wzdluz_sciany(logika*m,char*token)
{
  
  eksploruj(m,token);
  if(strcmp(m->gra->direction,"E")==0)
  {
  while(rusz_naprzod(m,token)!=1 && (m->swiat->mapa[interpretuj_wspolrzedna_y(m)+1][interpretuj_wspolrzedna_x(m)]=='w'))
  {
    eksploruj(m,token);
    
  }
  }

  if(strcmp(m->gra->direction,"W")==0)
  {
  while(rusz_naprzod(m,token)!=1 && (m->swiat->mapa[interpretuj_wspolrzedna_y(m)-1][interpretuj_wspolrzedna_x(m)]=='w'))
  {
    eksploruj(m,token);
  }
  }

  if(strcmp(m->gra->direction,"N")==0)
  {
  while(rusz_naprzod(m,token)!=1 && (m->swiat->mapa[interpretuj_wspolrzedna_y(m)][interpretuj_wspolrzedna_x(m)-1]=='w'))
  {
    eksploruj(m,token);
  }
  }

  if(strcmp(m->gra->direction,"S")==0)
  {
  while(rusz_naprzod(m,token)!=1 && (m->swiat->mapa[interpretuj_wspolrzedna_y(m)][interpretuj_wspolrzedna_x(m)+1]=='w'))
  {
    eksploruj(m,token);
  }
  }
}

int petla(logika*m,char*token)
{
  int k=0;
  int s=0;
  int x=m->gra->current_x;
  int y=m->gra->current_y;
  eksploruj(m,token);
  while(m->swiat->mapa[m->graex->x[1]][m->graex->y[1]]=='w')
  {
    rotate_right(token);
    wczytaj_zapisz(m);
  }

  //w funkcji eksploruj dodac ifa ze jesli wszystkie 3 odkryte pola sa to pominac funkcje
while(m->gra->current_x!=x || m->gra->current_y!=y || (s!=4 && s!=-4))
{
idz_wzdluz_sciany(m,token);
if(strcmp(m->gra->direction,"E")==0)
{
  
if(m->swiat->mapa[interpretuj_wspolrzedna_y(m)+1][interpretuj_wspolrzedna_x(m)]!='w')
{
  rotate_left(token);
  wczytaj_zapisz(m);
  s=s-1;
}
else
{
  rotate_right(token);
  s=s+1;
  wczytaj_zapisz(m);

}
}
else if(strcmp(m->gra->direction,"W")==0)
{
if(m->swiat->mapa[interpretuj_wspolrzedna_y(m)-1][interpretuj_wspolrzedna_x(m)]!='w')
{
  rotate_left(token);
  wczytaj_zapisz(m);
  s=s-1;
}
else
{
  rotate_right(token);
  s=s+1;
  wczytaj_zapisz(m);

}
}
else if(strcmp(m->gra->direction,"N")==0)
{
if(m->swiat->mapa[interpretuj_wspolrzedna_y(m)][interpretuj_wspolrzedna_x(m)-1]!='w')
{
  rotate_left(token);
  wczytaj_zapisz(m);
  s=s-1;
}
else
{
  rotate_right(token);
  s=s+1;
  wczytaj_zapisz(m);

}
}
else if(strcmp(m->gra->direction,"S")==0)
{
if(m->swiat->mapa[interpretuj_wspolrzedna_y(m)][interpretuj_wspolrzedna_x(m)+1]!='w')
{
  rotate_left(token);
  wczytaj_zapisz(m);
  s=s-1;
}
else
{
  rotate_right(token);
  s=s+1;
  wczytaj_zapisz(m);

}
}

}

if(s==4)
return 1;
else if(s==-4)
return -1;
  

}

void bot(logika*m,char*token)
{
  idz_do_sciany(m,token);
  petla(m,token);
}

