#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    double re;
    double im;
} complex;

typedef struct {
    u_int m;
    u_int n;
    u_int max_m;
    u_int max_n;
    u_int max_size;
    complex *base;
    complex **me;
} ZMAT;

extern ZMAT *QR;
extern ZMAT *Rout;
extern u_int i;
extern u_int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    u_int i_start = 1;
    u_int stride = 2;
    for (i = i_start; i < QR->m; i += stride) {
        for (j = 0; j < QR->n && j < i; j++) {
            Rout->me[i][j].re = 0.;
            Rout->me[i][j].im = 0.;
            if (i + 1 < QR->m) {
                Rout->me[i+1][j].re = 0.;
                Rout->me[i+1][j].im = 0.;
            }
        }
    }
    for (i = (QR->m % 2 == 1) ? QR->m - 1 : QR->m - 2; i < QR->m; i++) {
        for (j = 0; j < QR->n && j < i; j++) {
            Rout->me[i][j].re = Rout->me[i][j].im = 0.;
        }
    }
}
