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
if (N > 0) {
    i = 0;
    for (int outer = 0; outer < 1; outer++) {
        do {
            (((float *)C)[2 * (ldc * i + i) + 1]) = 0.;
            i++;
        } while (i < N);
    }
}
}
