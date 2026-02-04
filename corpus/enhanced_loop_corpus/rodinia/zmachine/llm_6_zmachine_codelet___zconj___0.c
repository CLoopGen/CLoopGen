#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    double re;
    double im;
} complex;

extern complex *zp;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_im;
    for (i = 0; i < len; i++) {
        temp_im = zp[i].im;
        zp[i].im = -temp_im;
    }
}
