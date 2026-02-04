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
    // Variant 1: Consecutive memory access by flattening the 2D array into a 1D stride
    complex *base = Rout->me[0];
    u_int n = Rout->n;
    for (i = 1; i < QR->m; i++) {
        u_int row_start = i * n;
        for (j = 0; j < QR->n && j < i; j++) {
            u_int idx = row_start + j;
            base[idx].re = 0.;
            base[idx].im = 0.;
        }
    }
}
