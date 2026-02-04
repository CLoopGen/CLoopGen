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
    for (int i = 0; i < overlap * 2; i++) {
        int index = i / 2;
        float val = x[index] * window[index];
        if (i % 2 == 0) {
            xx[index] = val;
        } else {
            xx[n - index - 1] = val;
        }
    }
}
