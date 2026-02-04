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
for (y = 0; y < b_h; y += 2) {
    for (x = 0; x < b_w + 1; x++) {
        // Process two rows simultaneously to increase computational intensity
        int offset0 = x + (8 / 2 - 4) * stride;
        int offset1 = x + (8 / 2 - 3) * stride;
        int offset2 = x + (8 / 2 - 2) * stride;
        int offset3 = x + (8 / 2 - 1) * stride;
        int offset4 = x + (8 / 2 + 0) * stride;
        int offset5 = x + (8 / 2 + 1) * stride;
        int offset6 = x + (8 / 2 + 2) * stride;
        int offset7 = x + (8 / 2 + 3) * stride;

        int a_1 = src[offset0], a_1_next = (y+1 < b_h) ? *(src + stride + offset0) : a_1;
        int a0 = src[offset1], a0_next = (y+1 < b_h) ? *(src + stride + offset1) : a0;
        int a1 = src[offset2], a1_next = (y+1 < b_h) ? *(src + stride + offset2) : a1;
        int a2 = src[offset3], a2_next = (y+1 < b_h) ? *(src + stride + offset3) : a2;
        int a3 = src[offset4], a3_next = (y+1 < b_h) ? *(src + stride + offset4) : a3;
        int a4 = src[offset5], a4_next = (y+1 < b_h) ? *(src + stride + offset5) : a4;
        int a5 = src[offset6], a5_next = (y+1 < b_h) ? *(src + stride + offset6) : a5;
        int a6 = src[offset7], a6_next = (y+1 < b_h) ? *(src + stride + offset7) : a6;

        int am = 0, am_next = 0;
        if (!p || p->fast_mc) {
            am = (20 * (a2 + a3) - 5 * (a1 + a4) + (a0 + a5) + 16) >> 5;
            am_next = (20 * (a2_next + a3_next) - 5 * (a1_next + a4_next) + (a0_next + a5_next) + 16) >> 5;
        } else {
            am = (p->hcoeff[0] * (a2 + a3) + p->hcoeff[1] * (a1 + a4) + p->hcoeff[2] * (a0 + a5) + p->hcoeff[3] * (a_1 + a6) + 32) >> 6;
            am_next = (p->hcoeff[0] * (a2_next + a3_next) + p->hcoeff[1] * (a1_next + a4_next) + p->hcoeff[2] * (a0_next + a5_next) + p->hcoeff[3] * (a_1_next + a6_next) + 32) >> 6;
        }

        if (am & (~255)) am = ~(am >> 31);
        if (am_next & (~255)) am_next = ~(am_next >> 31);

        tmp2[x] = am;
        if (y + 1 < b_h)
            tmp2[x + 64] = am_next;
    }
    src += 2 * stride;
    tmp2 += 128;
}
}
