#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

int w = 16384;
int mid = 8192;
int size = 16384;
int thra = 30;
int thrb = 100;

uint8_t *src;
uint8_t **srcf;
uint8_t *dst;

void init_vars() {
    src = (uint8_t*)calloc(w, sizeof(uint8_t));
    dst = (uint8_t*)calloc(w, sizeof(uint8_t));
    srcf = (uint8_t**)calloc(size, sizeof(uint8_t*));

    for (int i = 0; i < size; i++) {
        srcf[i] = (uint8_t*)calloc(w, sizeof(uint8_t));
        for (int j = 0; j < w; j++) {
            srcf[i][j] = rand() % 256;
        }
    }

    for (int j = 0; j < w; j++) {
        src[j] = rand() % 256;
    }
}