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
    width = 1024;
    pixel_ptr = 0;
    size_t data_size = (size_t)height * width * 8 / 4;
    encoded = (unsigned char*)calloc(data_size, sizeof(unsigned char));
    if (!encoded) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    for (size_t i = 0; i < data_size; i++) {
        encoded[i] = (unsigned char)((i * 71 + 43) % 256);
    }
}

__attribute__((destructor))
void cleanup() {
    if (encoded) {
        free((void*)encoded);
        encoded = NULL;
    }
}