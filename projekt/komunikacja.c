#include"komunikacja.h"







static size_t write_callback(void *data, size_t size, size_t nmemb, void *userp)
{
    /* to jest rzeczywista liczba bajtów przekazanych przez curl */
    size_t realsize = size * nmemb;

    /* jawnie konwertujemy (void*) na naszą strukturę, bo wiemy, że będziemy ją tutaj otrzymywać */
    Memory *mem = (Memory *) userp;

    char *ptr = NULL;

    /* Sprawdzamy czy pierwszy raz wywołujemy funkcję i trzeba zaalokować pamięć po raz pierwszy,
    czy trzeba zrobić reallokację (która kopiuje automatycznie starą zawartość w nowe miejsce) */
    if (mem->response != NULL)
        ptr = realloc(mem->response, mem->size + realsize + 1);
    else
        ptr = malloc(mem->size + realsize + 1);

    if (ptr == NULL)
        return 0; /* brak pamięci! */

    /* teraz zapamiętujemy nowy wskaźnik i doklejamy na końcu dane przekazane przez curl w 
       obszarze pamięci wskazywanym przez data */
    mem->response = ptr;
    memcpy(&(mem->response[mem->size]), data, realsize);
    mem->size += realsize;
    mem->response[mem->size] = 0; // to na końcu dodajemy bo to w końcu string, i zawsze powinien się skończyć!

    return realsize;
}

void make_request(char*url)
{
    CURL *curl;
    CURLcode res;
    Memory chunk;
    chunk.size = 0;
    chunk.response = NULL;

    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        //curl_easy_setopt(curl, CURLOPT_HEADER, 1L);

        /* to jest funkcja 'callback', która będzie wywołana przez curl gdy odczyta on kawałek danych
       ta funkcja musi mieć wywołanie zgodne z wymaganiami, które możesz sprawdzić tutaj:
       https://curl.se/libcurl/c/CURLOPT_WRITEFUNCTION.html */
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);

        /* to jest adress struktury, który będzie przekazywany do naszej funkcji 'callback',
       do tej struktury nasz funkcja 'callback' będzie dopisywać wynik */
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);

        /* Wykonaj zapytanie 'synchronicznie', to znaczy następna linijka kodu nie wykona się
       dopóki nie nadejdzie odpowiedź z serwera. */
        res = curl_easy_perform(curl);

        /* Sprawdzamy czy wystapił jakis błąd? */
        if (res != CURLE_OK)
        {
            fprintf(stderr, "Błąd! curl_easy_perform() niepowodzenie: %s\n", curl_easy_strerror(res));
            
        }    
        else
        {
           FILE *fin= fopen("odp.json","w+");
           fprintf(fin,"%s", chunk.response);
           fclose(fin);
            printf("%s\n", chunk.response);
            
        }

        /* zawsze po sobie sprzątaj */
        free(chunk.response);
        curl_easy_cleanup(curl);
    }
    
    
}
//void zapis(char*fnazwa)
//{
//    FILE* fin=fopen(fnazwa,"w+");
//    
//}

void info(char *token) 
{
    char *url; 
    char *url_bez_swiata="http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/info/";
    url = (char*) malloc((sizeof(char) * (strlen(url_bez_swiata)+1)) + (sizeof(char) *(strlen((token) + 1)))+10);
    strcpy(url,url_bez_swiata);
    strcat(url,token);
    make_request(url);
    free(url);
    
}

void move(char*token)
{
    char *url; 
    char *url_bez_swiata="http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/move/";
    url = (char*) malloc((sizeof(char) * strlen((url_bez_swiata)+1)) + (sizeof(char) *strlen((token) + 1))+10);
    strcpy(url,url_bez_swiata);
    strcat(url,token);
    make_request(url);
    free(url);
}


void explore(char*token)
{
    char *url; 
    char *url_bez_swiata="http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/explore/";
    url = (char*) malloc((sizeof(char) * strlen((url_bez_swiata)+1)) + (sizeof(char) *strlen((token) + 1))+10);
    strcpy(url,url_bez_swiata);
    strcat(url,token);
    make_request(url);
    free(url);
}

void rotate_left(char*token)
{   
    
    char *url; 
    char *url_bez_swiata="http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/rotate/";
    url = (char*) malloc((sizeof(char) * strlen(url_bez_swiata)+1) + (sizeof(char) *strlen((token) + 1))+10);
    strcpy(url,url_bez_swiata);
    strcat(url,token);
    strcat(url,"/left");
    make_request(url);
    free(url);
    
}

void rotate_right(char*token)
{   
    char *url; 
    char *url_bez_swiata="http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/rotate/";
    url = (char*) malloc((sizeof(char) * strlen(url_bez_swiata)+1) + (sizeof(char) *strlen((token) + 1))+10);
    strcpy(url,url_bez_swiata);
    strcat(url,token);
    strcat(url,"/right");
    make_request(url);
   // printf("%s\n",url);
    free(url);
    

}

void reset(char*token)
{
    char *url; 
    char *url_bez_swiata="http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/reset/";
    url = (char*) malloc((sizeof(char) * strlen((url_bez_swiata)+1)) + (sizeof(char) *strlen((token) + 1))+10);
    strcpy(url,url_bez_swiata);
    strcat(url,token);
    make_request(url);
    free(url);
}



//int main(int argc, char **argv)
//{
//    char*token;
//    for(int i=2;argv[i]!=NULL;i++)
//    {
//    if(strcmp("info", argv[i]) == 0)
//    info(argv[1]);
//    if(strcmp("rotate_right", argv[i]) == 0)
//    rotate_right(argv[1]);
//    if(strcmp("rotate_left", argv[i]) == 0)
//    rotate_left(argv[1]);
//    if(strcmp("move", argv[i]) == 0)
//    move(argv[1]);
//    if(strcmp("explore", argv[i]) == 0)
//    explore(argv[1]);
//    }
//    return 0;
//}