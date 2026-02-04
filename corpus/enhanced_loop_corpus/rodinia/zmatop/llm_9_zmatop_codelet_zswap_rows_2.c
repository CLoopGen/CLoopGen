#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    double re;
    double im;
} complex;

extern int i;
extern int j;
extern int lo;
extern int hi;
extern int k;
extern complex **A_me;
extern complex tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = lo; k <= hi; k++) {
    double re_i = A_me[k][i].re;
    double im_i = A_me[k][i].im;
    double re_j = A_me[k][j].re;
    double im_j = A_me[k][j].im;

    // Perform complex conjugation during swap to increase arithmetic operations
    A_me[k][i].re = re_j;
    A_me[k][i].im = -im_j;
    A_me[k][j].re = re_i;
    A_me[k][j].im = -im_i;
}
}
