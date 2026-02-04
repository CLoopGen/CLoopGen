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
        if (i % 2 == 0) {
            xx[i] = x[i] * window[i];
        } else {
            xx[n - i - 1] = x[n - i - 1] * window[i];
        }
    }
}
