#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern int n1;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int step = (n1 > n2) ? 1 : 2;
for (i = 0; i < n1; i += step) {
    for (j = 0; j < n2; j++) {
        float *base = &((float *)C)[2 * (ldc * i + j)];
        base[0] = 0.0f;
        base[1] = 0.0f;
        base[2] = 0.0f;
        base[4] = 0.0f;
        base[6] = 0.0f;
    }
}
}
