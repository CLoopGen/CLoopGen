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
    float temp[864] = {0};
    for (int i = 0; i < overlap; i++) {
        temp[i] = x[i] * window[i];
        temp[n - i - 1] = x[n - i - 1] * window[i];
    }
    for (int i = 0; i < overlap; i++) {
        xx[i] = temp[i];
        xx[n - i - 1] = temp[n - i - 1];
    }
}
