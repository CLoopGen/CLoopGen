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

extern ZMAT *A;
extern int i;
extern int j;
extern complex **A_me;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < A->m; i++)
        A_me[i][i-1].re = A_me[i][i-1].im = 0.;
}
