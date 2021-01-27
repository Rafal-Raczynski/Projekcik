#ifndef obrazek_h
#define obrazek_h

#include <png.h>
#include "logika.h"

void read_png_file(char *filename, int *width, int *height, 
     png_byte *color_type,  
     png_byte *bit_depth, png_bytep **row_pointers);

void write_png_file(char *filename, int width, int height, 
     png_byte color_type,  
     png_byte bit_depth, png_bytep *row_pointers);

void process_png_file(int width, int height, png_bytep *row_pointers);

void init_png_file(int width, int height, png_bytep *row_pointers);

void copy_tile(int xs, int ys, int width, int height, png_bytep *row_pointers, png_bytep *row_pointers_from, int idx);

png_bytep * create_image(int width, int height);

void png_mapka( mapka* x);

int ktory_numer(char x);

#endif