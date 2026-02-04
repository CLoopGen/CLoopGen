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
for (y = 0; y < b_h; y += 2) {
    for (x = 0; x < b_w; x++) {
        int a_1 = tmpI[x + (4 - 4) * 64];
        int a0 = tmpI[x + (4 - 3) * 64];
        int a1 = tmpI[x + (4 - 2) * 64];
        int a2 = tmpI[x + (4 - 1) * 64];
        int a3 = tmpI[x + (4 + 0) * 64];
        int a4 = tmpI[x + (4 + 1) * 64];
        int a5 = tmpI[x + (4 + 2) * 64];
        int a6 = tmpI[x + (4 + 3) * 64];

        int am = 0;
        if (!p || p->fast_mc) {
            am = (20 * (a2 + a3) - 5 * (a1 + a4) + (a0 + a5) + 512) >> 10;
        } else {
            am = (p->hcoeff[0] * (a2 + a3) + p->hcoeff[1] * (a1 + a4) +
                  p->hcoeff[2] * (a0 + a5) + p->hcoeff[3] * (a_1 + a6) + 2048) >> 12;
        }

        if (am & (~255))
            am = ~(am >> 31);
        tmp2[x] = am;

        if (y + 1 < b_h) {
            int offset_next = 64;
            int a_1n = tmpI[offset_next + x + (4 - 4) * 64];
            int a0n = tmpI[offset_next + x + (4 - 3) * 64];
            int a1n = tmpI[offset_next + x + (4 - 2) * 64];
            int a2n = tmpI[offset_next + x + (4 - 1) * 64];
            int a3n = tmpI[offset_next + x + (4 + 0) * 64];
            int a4n = tmpI[offset_next + x + (4 + 1) * 64];
            int a5n = tmpI[offset_next + x + (4 + 2) * 64];
            int a6n = tmpI[offset_next + x + (4 + 3) * 64];

            int amn = 0;
            if (!p || p->fast_mc) {
                amn = (20 * (a2n + a3n) - 5 * (a1n + a4n) + (a0n + a5n) + 512) >> 10;
            } else {
                amn = (p->hcoeff[0] * (a2n + a3n) + p->hcoeff[1] * (a1n + a4n) +
                       p->hcoeff[2] * (a0n + a5n) + p->hcoeff[3] * (a_1n + a6n) + 2048) >> 12;
            }

            if (amn & (~255))
                amn = ~(amn >> 31);
            tmp2[offset_next + x] = amn;
        }
    }
    tmpI += 128;
    tmp2 += 128;
}
}
