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
unsigned char uq;
unsigned char vq;

void init_vars() {
    height = 1024;
    width = 1536; 

    encoded = (unsigned char*)calloc(width * height * 6 / 4, sizeof(unsigned char));
    if (!encoded) {
        exit(1);
    }

    pixel_ptr = 0;
    yq = 128;
    uq = 64;
    vq = 32;
}