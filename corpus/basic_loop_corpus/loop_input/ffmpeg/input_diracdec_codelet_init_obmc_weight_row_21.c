#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct DWTPlane {
    int width;
    int height;
    int stride;
    uint8_t *buf;
    uint8_t *buf_base;
    uint8_t *tmp;
} DWTPlane;

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

typedef struct Plane {
    DWTPlane idwt;
    int width;
    int height;
    ptrdiff_t stride;
    uint8_t xblen;
    uint8_t yblen;
    uint8_t xbsep;
    uint8_t ybsep;
    uint8_t xoffset;
    uint8_t yoffset;
    SubBand band[5][4];
} Plane;

Plane *p;
uint8_t *obmc_weight;
int wy;
int x;

void init_vars() {
    p = (Plane*)calloc(1, sizeof(Plane));
    if (!p) exit(1);

    p->xblen = 100000; // ensures loop runs ~0.01s on modern CPU
    p->yblen = 1;
    p->xbsep = 0;
    p->ybsep = 0;
    p->xoffset = 0;
    p->yoffset = 0;

    obmc_weight = (uint8_t*)calloc(p->xblen, sizeof(uint8_t));
    if (!obmc_weight) exit(1);

    wy = 32;
    x = 0;
}