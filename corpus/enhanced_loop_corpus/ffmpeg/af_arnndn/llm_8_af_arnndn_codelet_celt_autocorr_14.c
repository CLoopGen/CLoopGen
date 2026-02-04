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
    for (int i = 0; i < overlap; i += 2) {
        if (i < overlap) {
            xx[i] = x[i] * window[i];
            xx[n - i - 1] = x[n - i - 1] * window[i];
        }
        if (i + 1 < overlap) {
            xx[i + 1] = x[i + 1] * window[i + 1];
            xx[n - i - 2] = x[n - i - 2] * window[i + 1];
        }
    }
}
