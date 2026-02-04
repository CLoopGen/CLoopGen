#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *x;
extern int n;
extern float xx[864];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < n && i < 864; i += 2) {
        xx[i] = x[i];
        if (i + 1 < n && i + 1 < 864) {
            xx[i + 1] = x[i + 1];
        }
    }
}
