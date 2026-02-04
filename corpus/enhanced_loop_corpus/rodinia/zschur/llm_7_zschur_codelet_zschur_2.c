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
extern int k;
extern int k_min;
extern int k_max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    complex temp;
    temp.re = 0.;
    temp.im = 0.;
    for (int j = k_min; j <= k_max - 2; j++) {
        A->me[j + 2][j] = temp;
    }
}
