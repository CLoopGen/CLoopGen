#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *output;
extern  float *input;
extern  float iir[5][4];
extern float hist[5][2];
extern ptrdiff_t factor;
extern float res;
extern float tmp;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i++) {
        res = input[i * factor]; // Strided read from input with step 'factor'
        for (j = 0; j < factor; j++) {
            for (k = 0; k < 5; k++) {
                ptrdiff_t idx = j * 5 + k; // Flatten inner loop index for indirect-like access
                float *h = &hist[0][0] + 2 * k;
                float *ii = &iir[0][0] + 4 * k;
                tmp = h[0] * ii[0] + h[1] * ii[1] + res;
                res = h[0] * ii[2] + h[1] * ii[3] + tmp;
                h[0] = h[1];
                h[1] = tmp;
            }
            output[i * factor + j] = res; // Write to output with 2D layout flattened
            res = 0;
        }
    }
}
