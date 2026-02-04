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
    if (len > 0) {
        zp[0].im = -zp[0].im;
        for (i = 1; i < len; i++) {
            zp[i].im = -zp[i-1].im;
        }
    }
}
