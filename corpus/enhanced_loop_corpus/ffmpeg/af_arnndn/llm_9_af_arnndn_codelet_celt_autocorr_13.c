#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *x;
extern int n;
extern float xx[864];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < n && i < 864; i++) {
        float val = x[i] * 1.5f + 0.3f;
        xx[i] = val * val;
    }
}
