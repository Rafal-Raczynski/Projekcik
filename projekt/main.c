#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "komunikacja.h"
#include "cjsonik.h"
#include "mapa.h"
#include "logika.h"





int main(int argc, char **argv)
{
    char komenda [20];
    logika* wizualizacja;
    char*token;
    wizualizacja=poczatek(argv[1]);
    if(strcmp(argv[2],"bot")==0)
    bot(wizualizacja,argv[1]);

    if(strcmp(argv[2],"play")==0)
    {
        while(1)
        {
            fgets(komenda,20,stdin);
            strcpy(komenda, strtok(komenda, "\n"));
            if(strcmp(komenda, "reset") == 0)
            {
                reset(argv[1]);
                wizualizacja=poczatek(argv[1]);
            }
            if(strcmp(komenda, "move") == 0)
            {
                rusz_naprzod(wizualizacja,argv[1]);
                printf("Aktualne współrzędne czołgu:x=%d,y=%d\n",interpretuj_wspolrzedna_x(wizualizacja)+1,interpretuj_wspolrzedna_y(wizualizacja)+1);
                printf("Kierunek zwrotu czołgu:%s\n",wizualizacja->gra->direction);
            }
            if(strcmp(komenda, "rotate_left") == 0)
            {
                rotate_left(argv[1]);
                wczytaj_zapisz(wizualizacja);
                printf("Aktualne współrzędne czołgu:x=%d,y=%d\n",interpretuj_wspolrzedna_x(wizualizacja)+1,interpretuj_wspolrzedna_y(wizualizacja)+1);
                printf("Kierunek zwrotu czołgu:%s\n",wizualizacja->gra->direction);
            }
            if(strcmp(komenda, "rotate_right") == 0)
            {
                rotate_right(argv[1]);
                wczytaj_zapisz(wizualizacja);
                printf("Aktualne współrzędne czołgu:x=%d,y=%d\n",interpretuj_wspolrzedna_x(wizualizacja)+1,interpretuj_wspolrzedna_y(wizualizacja)+1);
                printf("Kierunek zwrotu czołgu:%s\n",wizualizacja->gra->direction);
            }
            if(strcmp(komenda, "koniec_gry") == 0)
            {
                break;
            }
            if(strcmp(komenda, "explore") == 0)
            {
                eksploruj(wizualizacja,argv[1]);
                printf("Aktualne współrzędne czołgu:x=%d,y=%d\n",interpretuj_wspolrzedna_x(wizualizacja)+1,interpretuj_wspolrzedna_y(wizualizacja)+1);
                printf("Kierunek zwrotu czołgu:%s\n",wizualizacja->gra->direction);
            }
            if(strcmp(komenda, "info") == 0)
            {
                info(argv[1]);
                wczytaj_zapisz(wizualizacja);
                printf("Aktualne współrzędne czołgu:x=%d,y=%d\n",interpretuj_wspolrzedna_x(wizualizacja)+1,interpretuj_wspolrzedna_y(wizualizacja)+1);
                printf("Kierunek zwrotu czołgu:%s\n",wizualizacja->gra->direction);
            }
        }
    }


    zwolnij_stan(wizualizacja->gra);
    zwolnij(wizualizacja->swiat);
    zwolnij_stan_ex(wizualizacja->graex);
    free(wizualizacja);

    return 0;
}