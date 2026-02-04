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

extern ZMAT *in;
extern ZMAT *out;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < in->m; i++) {
        int skip = (i + 1) % 3;
        for (j = 0; j < in->n; j++) {
            if (skip) {
                skip--;
                continue;
            }
            out->me[j][i].re = in->me[i][j].re;
            out->me[j][i].im = -in->me[i][j].im;
        }
    }
}
