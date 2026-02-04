#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int N;
extern int *cindex;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N * 2 - 2; i++) {
        cindex[i % (N - 1)] = (i + 1) % N;
    }
}
