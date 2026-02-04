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
for (i = 0; i < N && N > 0; i++) {
    for (int k = 0; k < 1; k++) {
        (((float *)C)[2 * (ldc * i + i) + 1]) = 0.;
    }
}
}
