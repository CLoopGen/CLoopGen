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
    int *indices = (int*)malloc(len * sizeof(int));
    for (int j = 0; j < len; j++) {
        indices[j] = len - 1 - j;
    }
    for (i = 0; i < len; i++) {
        int idx = indices[i];
        out[idx].re = zp1[idx].re + zp2[idx].re;
        out[idx].im = zp1[idx].im + zp2[idx].im;
    }
    free(indices);
}
