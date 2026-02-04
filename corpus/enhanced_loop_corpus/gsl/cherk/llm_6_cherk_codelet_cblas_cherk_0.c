#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    for (j = i; j < N; j++) {
        float *base = (float *)C + 2 * (ldc * i + j);
        base[0] = 0.;
        base[1] = 0.;
        // Introduce a WAW dependency by writing same location twice (redundant but valid)
        base[0] = 0.; 
    }
}
}
