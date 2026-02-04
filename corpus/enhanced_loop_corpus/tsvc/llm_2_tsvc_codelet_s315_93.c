#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 4
    for (int i = 0; i < 32000; i += 4) {
        a[i] = (i * 7) % 32000;
        if (i + 1 < 32000) a[i + 1] = ((i + 1) * 7) % 32000;
        if (i + 2 < 32000) a[i + 2] = ((i + 2) * 7) % 32000;
        if (i + 3 < 32000) a[i + 3] = ((i + 3) * 7) % 32000;
    }
}
