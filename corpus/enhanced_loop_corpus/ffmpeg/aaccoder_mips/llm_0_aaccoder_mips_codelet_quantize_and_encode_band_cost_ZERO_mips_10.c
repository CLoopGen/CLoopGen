#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *out;
extern int size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < size; j += 8) {
        for (i = j; i < j + 8 && i < size; i++) {
            out[i] = 0.F;
        }
    }
}
