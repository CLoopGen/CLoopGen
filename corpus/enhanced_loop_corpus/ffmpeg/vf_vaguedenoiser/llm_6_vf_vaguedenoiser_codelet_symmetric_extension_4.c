#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *output;
extern int last;
extern  int originalLast;
extern int i;
extern int nextend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int idx = last;
    for (i = 0; i < nextend; i++) {
        idx++;
        output[idx] = output[originalLast - 1 - i];
    }
    last = idx;
}
