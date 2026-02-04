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

extern ZMAT *H;
extern int i;
extern int j;
extern int limit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double val_re, val_im;
    for (i = 1; i < limit; i++) {
        val_re = 0.; // Move assignment outside inner loop to create WAW-like independence
        val_im = 0.;
        for (j = 0; j < i - 1; j++) {
            H->me[i][j].re = val_re;
            H->me[i][j].im = val_im;
        }
    }
}
