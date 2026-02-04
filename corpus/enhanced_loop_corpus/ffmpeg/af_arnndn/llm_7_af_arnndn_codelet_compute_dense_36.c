#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *output;
extern  int N;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (N > 0) {
        output[0] = (0 > output[0]) ? 0 : output[0];
        for (int i = 1; i < N; i++) {
            output[i] = ((output[i-1]) > (output[i]) ? (output[i-1]) : (output[i]));
        }
    }
}
