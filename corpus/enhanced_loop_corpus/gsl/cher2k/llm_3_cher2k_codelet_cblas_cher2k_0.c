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
for (j = 0; j < N; j++) {
    for (i = 0; i <= j; i++) {
        int index = 2 * (ldc * i + j);
        ((float *)C)[index] = 0.;
        ((float *)C)[index + 1] = 0.;
    }
}
}
