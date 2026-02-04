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
    int idx = ldc * i;
    for (j = 0; j <= i; j++) {
        int offset = 2 * (idx + j);
        ((float *)C)[offset] = 0.;
        ((float *)C)[offset + 1] = ((float *)C)[offset]; // Introduce RAW: use previous value
    }
}
}
