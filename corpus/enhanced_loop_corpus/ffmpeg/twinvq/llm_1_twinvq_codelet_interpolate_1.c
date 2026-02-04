#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *out;
extern float v2;
extern int size;
extern int i;
extern float step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < size; i++) {
        for (int k = 0; k < 1; k++) {
            v2 += step;
            out[i] = v2;
        }
    }
}
