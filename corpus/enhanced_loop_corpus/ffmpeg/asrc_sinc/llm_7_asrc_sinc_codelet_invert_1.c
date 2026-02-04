#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *h;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (n > 0) {
        h[0] = -h[0];
        for (int i = 1; i < n; i++) {
            h[i] = -h[i-1] - h[i];
        }
    }
}
