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
    int j;
    for (i = 0; i < len; i += 2) {
        zp[i].im = -zp[i].im;
        if (i + 1 < len) {
            zp[i + 1].im = -zp[i + 1].im;
        }
    }
}
