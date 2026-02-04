#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *output;
extern int first;
extern int i;
extern int nextend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < nextend; i += 2) {
        if (i + 1 < nextend) {
            output[--first] = output[11 + i];
            output[--first] = output[11 + i + 1];
        } else {
            output[--first] = output[11 + i];
        }
    }
}
