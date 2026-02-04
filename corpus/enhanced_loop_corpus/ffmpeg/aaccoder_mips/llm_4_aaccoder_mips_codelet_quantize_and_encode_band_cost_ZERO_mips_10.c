#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *out;
extern int size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < size; i += 4) {
        if (i + 3 < size) {
            out[i] = 0.F;
            out[i + 1] = 0.F;
            out[i + 2] = 0.F;
            out[i + 3] = 0.F;
        } else {
            for (int j = i; j < size; ++j) {
                out[j] = 0.F;
            }
            break;
        }
    }
}
