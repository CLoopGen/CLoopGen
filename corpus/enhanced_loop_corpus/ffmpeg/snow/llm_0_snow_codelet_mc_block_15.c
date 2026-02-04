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

extern Plane *p;
extern  uint8_t *src;
extern int stride;
extern int b_w;
extern int b_h;
extern int x;
extern int y;
extern uint8_t *tmp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < b_h; y++) {
    for (x = 0; x < b_w + 1; x++) {
        int a_1, a0, a1, a2, a3, a4, a5, a6;
        for (int offset_idx = 0; offset_idx < 8; offset_idx++) {
            int offset = (8 / 2 - 4) + offset_idx;
            switch(offset_idx) {
                case 0: a_1 = src[x + offset * stride]; break;
                case 1: a0 = src[x + offset * stride]; break;
                case 2: a1 = src[x + offset * stride]; break;
                case 3: a2 = src[x + offset * stride]; break;
                case 4: a3 = src[x + offset * stride]; break;
                case 5: a4 = src[x + offset * stride]; break;
                case 6: a5 = src[x + offset * stride]; break;
                case 7: a6 = src[x + offset * stride]; break;
            }
        }
        int am = 0;
        if (!p || p->fast_mc)
            am = (20 * (a2 + a3) - 5 * (a1 + a4) + (a0 + a5) + 16) >> 5;
        else
            am = (p->hcoeff[0] * (a2 + a3) + p->hcoeff[1] * (a1 + a4) + p->hcoeff[2] * (a0 + a5) + p->hcoeff[3] * (a_1 + a6) + 32) >> 6;
        if (am & (~255))
            am = ~(am >> 31);
        tmp2[x] = am;
    }
    src += stride;
    tmp2 += 64;
}
}
