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
    int *indices = (int*)malloc(len * sizeof(int));
    for (int j = 0; j < len; j++) {
        indices[j] = len - 1 - j; // reverse access order
    }
    for (i = 0; i < len; i++) {
        int idx = indices[i];
        zp[idx].im = -zp[idx].im;
    }
    free(indices);
}
