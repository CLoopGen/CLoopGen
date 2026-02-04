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
    if (length > 1) {
        float prev = in[0];
        for (i = 1; i < length; i++) {
            float curr = in[i];
            sum2 += prev * curr;
            prev = curr;
        }
    }
}
