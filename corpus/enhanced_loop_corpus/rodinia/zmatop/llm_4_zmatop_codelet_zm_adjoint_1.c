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
extern int i;
extern int j;
extern complex tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i_start = 0;
for (i = i_start; i < in->m; i++) {
    for (j = 0; j < i; j++) {
        if (!(i > j)) continue;
        tmp.re = in->me[i][j].re;
        tmp.im = in->me[i][j].im;
        in->me[i][j].re = in->me[j][i].re;
        in->me[i][j].im = -in->me[j][i].im;
        in->me[j][i].re = tmp.re;
        in->me[j][i].im = -tmp.im;
    }
    if (i < in->m) {
        in->me[i][i].im = -in->me[i][i].im;
    }
}
}
