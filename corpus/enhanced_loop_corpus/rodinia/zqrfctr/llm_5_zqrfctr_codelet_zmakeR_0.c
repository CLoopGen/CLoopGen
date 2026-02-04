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
    for (i = 1; i < QR->m; i++) {
        u_int limit = (QR->n < i) ? QR->n : i;
        for (j = 0; j < limit; j++) {
            Rout->me[i][j].re = 0.;
            Rout->me[i][j].im = 0.;
        }
    }
}
