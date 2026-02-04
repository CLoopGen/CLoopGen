#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int DWTELEM;
typedef short IDWTELEM;

typedef struct x_and_coeff {
    int16_t x;
    uint16_t coeff;
} x_and_coeff;

typedef struct SubBand {
    int level;
    int stride;
    int width;
    int height;
    int qlog;
    DWTELEM *buf;
    IDWTELEM *ibuf;
    int buf_x_offset;
    int buf_y_offset;
    int stride_line;
    x_and_coeff *x_coeff;
    struct SubBand *parent;
    uint8_t state[519][32];
} SubBand;

typedef struct Plane {
    int width;
    int height;
    SubBand band[8][4];
    int htaps;
    int8_t hcoeff[4];
    int diag_mc;
    int fast_mc;
    int last_htaps;
    int8_t last_hcoeff[4];
    int last_diag_mc;
} Plane;

int y;
int b_h;
int b_w;
int x;
int stride;
uint8_t *src;
uint8_t *tmp2;
Plane *p;

void init_vars() {
    b_w = 64;
    b_h = 64;
    stride = 64;

    src = (uint8_t*)calloc(stride * (8 + 6), sizeof(uint8_t));
    tmp2 = (uint8_t*)calloc(64 * (b_h + 1), sizeof(uint8_t));

    p = (Plane*)calloc(1, sizeof(Plane));
    p->fast_mc = 0;
    p->hcoeff[0] = 20;
    p->hcoeff[1] = -5;
    p->hcoeff[2] = 1;
    p->hcoeff[3] = 1;

    for (int i = 0; i < 8 + 6; i++) {
        for (int j = 0; j < stride; j++) {
            src[j + i * stride] = rand() & 0xFF;
        }
    }

    y = 0;
    x = 0;
}