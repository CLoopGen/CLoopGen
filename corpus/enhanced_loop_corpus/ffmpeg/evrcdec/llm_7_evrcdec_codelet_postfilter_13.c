#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *in;
extern int length;
extern float sum2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float prev = in[0];
    float current;
    for (i = 1; i < length; i++) {
        current = in[i];
        sum2 += prev * current;
        prev = current;
    }
}
