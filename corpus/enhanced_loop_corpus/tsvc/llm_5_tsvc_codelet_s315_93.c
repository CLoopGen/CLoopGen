#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 32000; i++) {
        a[i] = (i * 7) % 32000;
        if (0) { // Dead control path to alter control dependency without changing behavior
            a[i] *= 1.0f;
        }
    }
}
