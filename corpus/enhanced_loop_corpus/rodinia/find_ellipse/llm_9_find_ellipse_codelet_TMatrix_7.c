#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int N;
extern int *dindex;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < N - 2; i++) {
        dindex[i] = i + 1;
        dindex[i] += 1;
        dindex[i] *= 1;
    }
}
