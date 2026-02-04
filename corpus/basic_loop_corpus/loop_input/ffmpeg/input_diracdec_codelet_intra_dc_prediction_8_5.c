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
int16_t *buf;
int x;

void init_vars() {
    b = (SubBand *)calloc(1, sizeof(SubBand));
    if (!b) exit(1);

    b->width = 1 << 20;  // ~1M elements for ~0.01 sec runtime

    buf = (int16_t *)calloc(b->width, sizeof(int16_t));
    if (!buf) exit(1);

    for (int i = 0; i < b->width; i++) {
        buf[i] = (int16_t)(i & 0xFF);
    }

    x = 0;
}