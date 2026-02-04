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
    for (x = 0; x < b_w; x += 4) {
        int a_1, a0, a1, a2, a3, a4, a5, a6;
        int am[4];

        for (int i = 0; i < 4; i++) {
            if (x + i >= b_w) break;
            a_1 = tmpI[(x + i) + (4 - 4) * 64];
            a0 = tmpI[(x + i) + (4 - 3) * 64];
            a1 = tmpI[(x + i) + (4 - 2) * 64];
            a2 = tmpI[(x + i) + (4 - 1) * 64];
            a3 = tmpI[(x + i) + (4 + 0) * 64];
            a4 = tmpI[(x + i) + (4 + 1) * 64];
            a5 = tmpI[(x + i) + (4 + 2) * 64];
            a6 = tmpI[(x + i) + (4 + 3) * 64];

            if (!p || p->fast_mc)
                am[i] = (20 * (a2 + a3) - 5 * (a1 + a4) + (a0 + a5) + 512) >> 10;
            else
                am[i] = (p->hcoeff[0] * (a2 + a3) + p->hcoeff[1] * (a1 + a4) + 
                         p->hcoeff[2] * (a0 + a5) + p->hcoeff[3] * (a_1 + a6) + 2048) >> 12;

            if (am[i] & (~255))
                am[i] = ~(am[i] >> 31);
        }

        for (int i = 0; i < 4 && (x + i) < b_w; i++)
            tmp2[x + i] = am[i];
    }
    tmpI += 64;
    tmp2 += 64;
}
}
