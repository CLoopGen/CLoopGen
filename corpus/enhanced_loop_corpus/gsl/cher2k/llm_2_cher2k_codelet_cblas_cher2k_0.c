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
    float *base_C = (float *)C + 2 * ldc * i;
    for (j = i; j < N; j++) {
        float *addr = base_C + 2 * j;
        addr[0] = 0.;
        addr[1] = 0.;
    }
}
}
