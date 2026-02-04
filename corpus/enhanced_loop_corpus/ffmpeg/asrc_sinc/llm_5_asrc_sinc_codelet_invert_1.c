#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *h;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            h[i] = -h[i];
        } else {
            continue;
        }
    }
}
