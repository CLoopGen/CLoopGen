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
    for (k = k_min; k <= k_max - 2; k += 2) {
        A->me[k + 2][k].re = A->me[k + 2][k].im = 0.;
        if (k + 1 <= k_max - 2) {
            A->me[k + 3][k + 1].re = A->me[k + 3][k + 1].im = 0.;
        }
    }
}
