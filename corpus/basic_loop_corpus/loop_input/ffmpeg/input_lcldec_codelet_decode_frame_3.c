#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned int pixel_ptr;
int row;
int col;
unsigned char *encoded;
int width = 1024;
int height = 1024;
unsigned char yq;
unsigned char uq;
unsigned char vq;

void init_vars() {
    encoded = (unsigned char*)calloc(width * height * 2, sizeof(unsigned char));
    if (!encoded) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}