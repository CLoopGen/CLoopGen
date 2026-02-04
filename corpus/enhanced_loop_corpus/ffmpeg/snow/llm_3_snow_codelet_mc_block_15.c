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
        int offsets[] = { (8/2-4)*stride, (8/2-3)*stride, (8/2-2)*stride, (8/2-1)*stride,
                          (8/2+0)*stride, (8/2+1)*stride, (8/2+2)*stride, (8/2+3)*stride };
        for (x = 0; x < b_w + 1; x++) {
            int data[8];
            for (int i = 0; i < 8; i++) {
                data[i] = src[x + offsets[i]];
            }
            int a_1 = data[0], a0 = data[1], a1 = data[2], a2 = data[3],
                a3 = data[4], a4 = data[5], a5 = data[6], a6 = data[7];
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
