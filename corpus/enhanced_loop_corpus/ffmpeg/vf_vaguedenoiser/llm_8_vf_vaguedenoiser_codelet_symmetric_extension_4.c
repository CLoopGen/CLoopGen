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
    int j;
    for (i = 0; i < nextend; i += 2) {
        j = originalLast - 1 - i;
        output[++last] = output[j];
        if (i + 1 < nextend) {
            output[++last] = output[j - 1];
        }
    }
}
