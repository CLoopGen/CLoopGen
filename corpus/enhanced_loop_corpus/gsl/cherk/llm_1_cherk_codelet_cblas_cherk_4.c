#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *C;
extern  int ldc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i += 2) {
    (((float *)C)[2 * (ldc * i + i) + 1]) = 0.;
    if (i + 1 < N) {
        (((float *)C)[2 * (ldc * (i + 1) + (i + 1)) + 1]) = 0.;
    }
}
}
