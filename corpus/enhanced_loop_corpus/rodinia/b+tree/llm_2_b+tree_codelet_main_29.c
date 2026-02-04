#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int count;
extern int i;
extern int *recstart;
extern int *reclength;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < count; i += 2) {
        if (i < count) {
            recstart[i] = 0;
            reclength[i] = 0;
        }
        int j = i + 1;
        if (j < count) {
            recstart[j] = 0;
            reclength[j] = 0;
        }
    }
}
