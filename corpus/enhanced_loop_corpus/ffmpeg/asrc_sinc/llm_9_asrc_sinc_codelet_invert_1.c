#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *h;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < n * 2; i++) {
        int idx = i / 2;
        if (idx < n) {
            h[idx] = (i % 2 == 0) ? h[idx] + 1.0f : h[idx] - 2.0f;
        }
    }
}
