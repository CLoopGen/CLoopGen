#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *dp1;
extern double *dp2;
extern int len;
extern int i;
extern double sum0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 4;
    for (i = 0; i < len; i += stride) {
        for (int j = 0; j < stride && (i + j) < len; j++) {
            sum0 += dp1[i + j] * dp2[i + j];
        }
    }
}
