#include "cjsonik.h"

int main()
{
    char buffer[2048];
    FILE *f = fopen("odp.txt", "r+");
    fread(buffer,1,2048,f);
    stan* gra=stan_gry(buffer);
    fclose(f);
    printf("x:%d y:%d\n",gra->current_x,gra->current_y);
    zwolnij_stan(gra);
}