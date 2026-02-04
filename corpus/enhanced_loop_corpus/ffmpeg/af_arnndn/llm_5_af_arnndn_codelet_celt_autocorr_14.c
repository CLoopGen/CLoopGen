#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *x;
extern  float *window;
extern int overlap;
extern int n;
extern float xx[864];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < overlap; i++) {
        if (x[i] >= 0.0f) {
            xx[i] = x[i] * window[i];
        }
        if (x[n - i - 1] < 0.0f) {
            xx[n - i - 1] = x[n - i - 1] * window[i];
        }
    }
}
