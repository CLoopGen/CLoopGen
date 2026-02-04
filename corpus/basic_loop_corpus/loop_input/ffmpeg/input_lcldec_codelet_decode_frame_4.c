#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned int pixel_ptr;
int row;
int col;
unsigned char *encoded;
int width;
int height;
unsigned char yq;
unsigned char y1q;
unsigned char uq;
unsigned char vq;

void init_vars() {
    height = 1024;
    width = 1536;
    
    size_t data_size = (size_t)height * width * 3;
    encoded = (unsigned char*)calloc(data_size, sizeof(unsigned char));
    
    for (size_t i = 0; i < data_size; i++) {
        encoded[i] = rand() % 256;
    }
    
    pixel_ptr = 0;
    row = 0;
    col = 0;
    yq = 0;
    y1q = 0;
    uq = 0;
    vq = 0;
}