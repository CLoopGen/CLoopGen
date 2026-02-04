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
    for (i = 0; i < nextend; i++) {
        int temp = originalLast - 1 - i;
        for (int k = 0; k < 1; k++) {
            output[++last] = output[temp];
        }
    }
}
