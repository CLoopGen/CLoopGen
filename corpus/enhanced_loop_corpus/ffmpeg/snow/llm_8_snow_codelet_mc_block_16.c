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
    for (x = 0; x < b_w; x += 2) {
        int16_t *base_ptr = tmpI + x;
        int a_1_even = base_ptr[(8/2 - 4)*64];
        int a0_even  = base_ptr[(8/2 - 3)*64];
        int a1_even  = base_ptr[(8/2 - 2)*64];
        int a2_even  = base_ptr[(8/2 - 1)*64];
        int a3_even  = base_ptr[(8/2 + 0)*64];
        int a4_even  = base_ptr[(8/2 + 1)*64];
        int a5_even  = base_ptr[(8/2 + 2)*64];
        int a6_even  = base_ptr[(8/2 + 3)*64];

        int am_even;
        if (!p || p->fast_mc)
            am_even = (20 * (a2_even + a3_even) - 5 * (a1_even + a4_even) + (a0_even + a5_even) + 512) >> 10;
        else
            am_even = (p->hcoeff[0]*(a2_even+a3_even) + p->hcoeff[1]*(a1_even+a4_even) + 
                       p->hcoeff[2]*(a0_even+a5_even) + p->hcoeff[3]*(a_1_even+a6_even) + 2048) >> 12;

        int am_even_clamped = (am_even & (~255)) ? ~(am_even >> 31) : am_even;

        tmp2[x] = (uint8_t)am_even_clamped;

        if (x + 1 < b_w) {
            int a_1_odd = base_ptr[1 + (8/2 - 4)*64];
            int a0_odd  = base_ptr[1 + (8/2 - 3)*64];
            int a1_odd  = base_ptr[1 + (8/2 - 2)*64];
            int a2_odd  = base_ptr[1 + (8/2 - 1)*64];
            int a3_odd  = base_ptr[1 + (8/2 + 0)*64];
            int a4_odd  = base_ptr[1 + (8/2 + 1)*64];
            int a5_odd  = base_ptr[1 + (8/2 + 2)*64];
            int a6_odd  = base_ptr[1 + (8/2 + 3)*64];

            int am_odd;
            if (!p || p->fast_mc)
                am_odd = (20 * (a2_odd + a3_odd) - 5 * (a1_odd + a4_odd) + (a0_odd + a5_odd) + 512) >> 10;
            else
                am_odd = (p->hcoeff[0]*(a2_odd+a3_odd) + p->hcoeff[1]*(a1_odd+a4_odd) + 
                          p->hcoeff[2]*(a0_odd+a5_odd) + p->hcoeff[3]*(a_1_odd+a6_odd) + 2048) >> 12;

            int am_odd_clamped = (am_odd & (~255)) ? ~(am_odd >> 31) : am_odd;

            tmp2[x+1] = (uint8_t)am_odd_clamped;
        }
    }
    tmpI += 64;
    tmp2 += 64;
}
}
