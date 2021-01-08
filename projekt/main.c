#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "komunikacja.h"
#include "cjsonik.h"





int main(int argc, char **argv)
{
    char*token;
    plansza h;
    for(int i=2;argv[i]!=NULL;i++)
    {
    if(strcmp("info", argv[i]) == 0)
    info(argv[1]);
    if(strcmp("rotate_right", argv[i]) == 0)
    rotate_right(argv[1]);
    if(strcmp("rotate_left", argv[i]) == 0)
    rotate_left(argv[1]);
    if(strcmp("move", argv[i]) == 0)
    move(argv[1]);
    if(strcmp("explore", argv[i]) == 0)
    explore(argv[1]);
    char buffer[2048];
	FILE *f = fopen("odp.txt", "r");
	fread(buffer,1,2048,f);
	fclose(f);
	h=stan_gry(buffer);
    wypisz_macierz(h);
    }
    return 0;
}