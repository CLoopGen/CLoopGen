#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct SubBand {
    int level;
    int orientation;
    int stride;
    int width;
    int height;
    int pshift;
    int quant;
    uint8_t *ibuf;
    struct SubBand *parent;
    unsigned int length;
    const uint8_t *coeff_data;
} SubBand;

SubBand *b;
uint32_t *buf;
int x;

void init_vars() {
    b = (SubBand *)calloc(1, sizeof(SubBand));
    if (!b) exit(1);

    b->width = 65536;

    buf = (uint32_t *)calloc(b->width, sizeof(uint32_t));
    if (!buf) exit(1);

    for (int i = 0; i < b->width; i++) {
        buf[i] = 1;
    }
}