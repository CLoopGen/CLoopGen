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
    for (i = 0; i < nextend; i++) {
        if (first > 0) {
            output[--first] = output[11 + i];
        }
    }
}
