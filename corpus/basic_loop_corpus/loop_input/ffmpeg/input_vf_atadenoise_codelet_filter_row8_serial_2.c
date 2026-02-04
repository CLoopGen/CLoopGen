#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int w = 16384;
int mid = 8;
int size = 16;
int thra = 30;
int thrb = 100;

uint8_t *src;
uint8_t **srcf;
uint8_t *dst;

void init_vars() {
    const int data_size = w;
    const int filter_size = size;

    src = (uint8_t*)aligned_alloc(32, data_size * sizeof(uint8_t));
    dst = (uint8_t*)aligned_alloc(32, data_size * sizeof(uint8_t));
    srcf = (uint8_t**)aligned_alloc(32, filter_size * sizeof(uint8_t*));

    for (int i = 0; i < filter_size; i++) {
        srcf[i] = (uint8_t*)aligned_alloc(32, data_size * sizeof(uint8_t));
    }

    srand(0);
    for (int x = 0; x < data_size; x++) {
        src[x] = rand() % 256;
        for (int i = 0; i < filter_size; i++) {
            srcf[i][x] = rand() % 256;
        }
        dst[x] = 0;
    }
}