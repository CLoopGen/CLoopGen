#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *out;
extern int size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < size; i++) {
        int remainder = i % 4;
        if (remainder == 0 || remainder == 1 || remainder == 2 || remainder == 3) {
            out[i] = 0.F;
        }
    }
}
