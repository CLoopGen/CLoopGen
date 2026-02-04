#include <stdio.h>

typedef struct {
    double real;
    double imag;
} dcomplex;

int xstart[3];
int ystart[3];
int zstart[3];
int xend[3];
int yend[3];
int zend[3];
dcomplex u1[128][256][256];
int j;
int q;
int r;
int s;
dcomplex chk;

void init_vars() {
    // Initialize array bounds to ensure valid access within u1
    xstart[0] = 1;
    ystart[0] = 1;
    zstart[0] = 1;
    xend[0] = 256;
    yend[0] = 256;
    zend[0] = 128;

    // Initialize other elements of the start/end arrays (unused in loop but defined)
    xstart[1] = xstart[2] = 1;
    ystart[1] = ystart[2] = 1;
    zstart[1] = zstart[2] = 1;
    xend[1] = xend[2] = 1;
    yend[1] = yend[2] = 1;
    zend[1] = zend[2] = 1;

    // Initialize chk to zero
    chk.real = 0.0;
    chk.imag = 0.0;

    // Initialize u1 with non-zero values to make accumulation meaningful
    for (int s = 0; s < 128; s++) {
        for (int r = 0; r < 256; r++) {
            for (int q = 0; q < 256; q++) {
                u1[s][r][q].real = (double)(s + r + q) * 0.001;
                u1[s][r][q].imag = (double)(s * r * q % 1000) * 0.001;
            }
        }
    }

    // Initialize loop counters (will be overwritten, but set to safe values)
    j = 0;
    q = 0;
    r = 0;
    s = 0;
}