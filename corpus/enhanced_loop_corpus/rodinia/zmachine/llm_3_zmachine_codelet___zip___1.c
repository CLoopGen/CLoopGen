#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    double re;
    double im;
} complex;

extern complex *zp1;
extern complex *zp2;
extern int len;
extern complex sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse sequential memory access (backward traversal)
    for (i = len - 1; i >= 0; i--) {
        sum.re += zp1[i].re * zp2[i].re + zp1[i].im * zp2[i].im;
        sum.im += zp1[i].re * zp2[i].im - zp1[i].im * zp2[i].re;
    }
}
