#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "komunikacja.h"
#include "cjsonik.h"
#include "eksploracja.h"





int main(int argc, char **argv)
{
    char*token;
    char buffer[2048];
   //FILE *f = fopen("odp.txt", "r");
   //fread(buffer,1,2048,f);
   //fclose(f);
    stanex* h;
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
    FILE *f = fopen("odp.txt", "r");
    fread(buffer,1,2048,f);
    h=stan_gry_ex(buffer);
    fclose(f);
    printf("%d\n",h->x1);
    printf("%d\n",h->y1);
    printf("%d\n",h->x2);
    printf("%d\n",h->y2);
    printf("%d\n",h->x3);
    printf("%d\n",h->y3);
    printf("%s\n",h->type1);
    printf("%s\n",h->type2);
    printf("%s\n",h->type3);
    //free(h);
    free(h->type1);
    free(h->type2);
    free(h->type3);
    }
    return 0;
}