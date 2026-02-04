#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *h;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < n; i++) {
        if (h[i] > 0.0f) {
            h[i] = -h[i];
        } else {
            h[i] = -h[i];
        }
    }
}
