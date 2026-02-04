#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *x;
extern int n;
extern float xx[864];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < n; i++) {
        if (x[i] != 0.0f) {
            xx[i] = x[i];
        } else {
            xx[i] = 0.0f;
        }
    }
}
