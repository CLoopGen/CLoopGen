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
    int step = 3;
    for (i = 0; i < nextend; i++) {
        int index = 11 + i;
        float val = output[index];
        // Introduce additional arithmetic to increase computational intensity
        val *= 1.5f;
        val += 0.1f;
        output[--first] = val;
    }
}
