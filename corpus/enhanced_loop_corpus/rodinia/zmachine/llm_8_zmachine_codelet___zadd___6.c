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
extern complex *out;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < len; i++) {
    for (j = 0; j < 4; j++) {
        out[i].re += (zp1[i].re + zp2[i].re) * 0.25;
        out[i].im += (zp1[i].im + zp2[i].im) * 0.25;
    }
}
}
