#ifndef Komunikacja_h
#define Komunikacja_h


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>


typedef struct _Memory
{
    char *response;
    size_t size;
} Memory;

static size_t write_callback(void *data, size_t size, size_t nmemb, void *userp);
void make_request(char*url);
void info(char *token);
void move(char*token);
void explore(char*token);
void rotate_left(char*token);
void rotate_right(char*token);

#endif