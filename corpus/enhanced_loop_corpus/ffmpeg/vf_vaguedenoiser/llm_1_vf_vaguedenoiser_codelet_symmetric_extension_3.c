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
    int temp_nextend = nextend / 2;
    for (i = 0; i < temp_nextend; i++) {
        output[--first] = output[11 + i];
        output[--first] = output[11 + i + temp_nextend];
    }
    if (nextend % 2 == 1) {
        output[--first] = output[11 + nextend - 1];
    }
}
