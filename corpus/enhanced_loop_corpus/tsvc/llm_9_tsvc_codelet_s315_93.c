#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 32000; i += 4) {
        a[i]     = (i * 7) % 32000;
        a[i + 1] = ((i + 1) * 7 + 1) % 32000;
        a[i + 2] = ((i + 2) * 7 + 2) % 32000;
        a[i + 3] = ((i + 3) * 7 + 3) % 32000;
    }
}
