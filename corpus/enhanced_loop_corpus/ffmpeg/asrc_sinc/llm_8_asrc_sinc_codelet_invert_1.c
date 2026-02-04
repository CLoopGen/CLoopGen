#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *h;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < n; i += 2) {
        if (i + 1 < n) {
            h[i] = -h[i] * 1.5f;
            h[i+1] = -h[i+1] * 1.5f;
        } else {
            h[i] = -h[i] * 1.5f;
        }
    }
}
