#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
};

unsigned int pixel_ptr;
int row;
int col;
unsigned char *encoded;
int width;
int height;
unsigned char yq;
int uqvq;

void init_vars() {
    width = 512;
    height = 512;
    size_t data_size = width * height * 3;
    encoded = (unsigned char*)aligned_alloc(32, data_size);
    if (!encoded) {
        exit(1);
    }
    for (size_t i = 0; i < data_size; i++) {
        encoded[i] = rand() % 256;
    }
}