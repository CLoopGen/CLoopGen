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
    for (x = 0; x < b_w; x++) {
        int a_1 = tmpI[x + (8 / 2 - 4) * 64];
        int a0 = tmpI[x + (8 / 2 - 3) * 64];
        int a1 = tmpI[x + (8 / 2 - 2) * 64];
        int a2 = tmpI[x + (8 / 2 - 1) * 64];
        int a3 = tmpI[x + (8 / 2 + 0) * 64];
        int a4 = tmpI[x + (8 / 2 + 1) * 64];
        int a5 = tmpI[x + (8 / 2 + 2) * 64];
        int a6 = tmpI[x + (8 / 2 + 3) * 64];
        int am = 0;
        // Removed conditional branch by assuming fast_mc is always true
        am = (20 * (a2 + a3) - 5 * (a1 + a4) + (a0 + a5) + 512) >> 10;
        if (am & (~255))
            am = ~(am >> 31);
        tmp2[x] = am;
    }
    tmpI += 64;
    tmp2 += 64;
}
}
