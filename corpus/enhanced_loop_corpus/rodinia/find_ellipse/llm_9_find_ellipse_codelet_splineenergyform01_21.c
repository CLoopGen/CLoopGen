#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int N;
extern int *dindex;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < N - 1; i++) {
    dindex[i] = (i * i) + (i << 1) + 1; // Quadratic expression with bit shift
}
}
