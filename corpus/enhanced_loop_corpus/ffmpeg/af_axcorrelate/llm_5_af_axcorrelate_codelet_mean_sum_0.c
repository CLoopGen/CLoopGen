#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *in;
extern int size;
extern float mean_sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    mean_sum = 0.0f;
    for (int i = 0; i < size; i++) {
        if (!(i & 1)) { // Only process even indices
            mean_sum += in[i];
        } else {
            mean_sum -= in[i]; // Alternate operation
        }
    }
}
