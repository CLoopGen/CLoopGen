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
    if (len > 0) {
        i = 0;
        for (; i < len; ) {
            out[i].re = zp1[i].re + zp2[i].re;
            out[i].im = zp1[i].im + zp2[i].im;
            i++;
        }
    }
}
