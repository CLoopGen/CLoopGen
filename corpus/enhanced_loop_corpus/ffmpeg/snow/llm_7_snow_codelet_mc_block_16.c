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
extern int b_w;
extern int b_h;
extern int x;
extern int y;
extern int16_t *tmpI;
extern uint8_t *tmp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < b_h; y++) {
    int16_t *local_tmpI = tmpI;
    uint8_t *local_tmp2 = tmp2;
    for (x = 0; x < b_w; x++) {
        int a_1 = local_tmpI[x + (4 - 4) * 64];
        int a0 = local_tmpI[x + (4 - 3) * 64];
        int a1 = local_tmpI[x + (4 - 2) * 64];
        int a2 = local_tmpI[x + (4 - 1) * 64];
        int a3 = local_tmpI[x + (4 + 0) * 64];
        int a4 = local_tmpI[x + (4 + 1) * 64];
        int a5 = local_tmpI[x + (4 + 2) * 64];
        int a6 = local_tmpI[x + (4 + 3) * 64];
        int am;
        if (!p || p->fast_mc) {
            int sum1 = a2 + a3;
            int sum2 = a1 + a4;
            int sum3 = a0 + a5;
            am = (20 * sum1 - 5 * sum2 + sum3 + 512) >> 10;
        } else {
            int sum1 = a2 + a3;
            int sum2 = a1 + a4;
            int sum3 = a0 + a5;
            int sum4 = a_1 + a6;
            am = (p->hcoeff[0] * sum1 + p->hcoeff[1] * sum2 + p->hcoeff[2] * sum3 + p->hcoeff[3] * sum4 + 2048) >> 12;
        }
        am = (am & (~255)) ? ~(am >> 31) : am;
        local_tmp2[x] = (uint8_t)am;
    }
    tmpI += 64;
    tmp2 += 64;
}
}
