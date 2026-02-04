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
    for (x = 0; x < b_w + 1; x += 2) {
        int a_1 = src[x + (8 / 2 - 4) * stride];
        int a0 = src[x + (8 / 2 - 3) * stride];
        int a1 = src[x + (8 / 2 - 2) * stride];
        int a2 = src[x + (8 / 2 - 1) * stride];
        int a3 = src[x + (8 / 2 + 0) * stride];
        int a4 = src[x + (8 / 2 + 1) * stride];
        int a5 = src[x + (8 / 2 + 2) * stride];
        int a6 = src[x + (8 / 2 + 3) * stride];

        int am0, am1;
        if (!p || p->fast_mc) {
            am0 = (20 * (a2 + a3) - 5 * (a1 + a4) + (a0 + a5) + 16) >> 5;
            // Unroll next element with bounds check
            if (x + 1 < b_w + 1) {
                int a_1n = src[(x+1) + (8/2-4)*stride];
                int a0n = src[(x+1) + (8/2-3)*stride];
                int a1n = src[(x+1) + (8/2-2)*stride];
                int a2n = src[(x+1) + (8/2-1)*stride];
                int a3n = src[(x+1) + (8/2+0)*stride];
                int a4n = src[(x+1) + (8/2+1)*stride];
                int a5n = src[(x+1) + (8/2+2)*stride];
                int a6n = src[(x+1) + (8/2+3)*stride];
                am1 = (20 * (a2n + a3n) - 5 * (a1n + a4n) + (a0n + a5n) + 16) >> 5;
            } else {
                am1 = am0;
            }
        } else {
            am0 = (p->hcoeff[0] * (a2 + a3) + p->hcoeff[1] * (a1 + a4) + p->hcoeff[2] * (a0 + a5) + p->hcoeff[3] * (a_1 + a6) + 32) >> 6;
            if (x + 1 < b_w + 1) {
                int a_1n = src[(x+1) + (8/2-4)*stride];
                int a0n = src[(x+1) + (8/2-3)*stride];
                int a1n = src[(x+1) + (8/2-2)*stride];
                int a2n = src[(x+1) + (8/2-1)*stride];
                int a3n = src[(x+1) + (8/2+0)*stride];
                int a4n = src[(x+1) + (8/2+1)*stride];
                int a5n = src[(x+1) + (8/2+2)*stride];
                int a6n = src[(x+1) + (8/2+3)*stride];
                am1 = (p->hcoeff[0] * (a2n + a3n) + p->hcoeff[1] * (a1n + a4n) + p->hcoeff[2] * (a0n + a5n) + p->hcoeff[3] * (a_1n + a6n) + 32) >> 6;
            } else {
                am1 = am0;
            }
        }

        if (am0 & (~255))
            am0 = ~(am0 >> 31);
        if (am1 & (~255))
            am1 = ~(am1 >> 31);

        tmp2[x] = am0;
        if (x + 1 < b_w + 1)
            tmp2[x+1] = am1;
    }
    src += stride;
    tmp2 += 64;
}
}
