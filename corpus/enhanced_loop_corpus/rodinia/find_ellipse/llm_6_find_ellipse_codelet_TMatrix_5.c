#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int N;
extern int *bindex;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N; i++) {
        bindex[i] = i;
        if (i > 0)
            bindex[i] += bindex[i-1]; // Introduces RAW and WAW loop-carried dependency
    }
}
