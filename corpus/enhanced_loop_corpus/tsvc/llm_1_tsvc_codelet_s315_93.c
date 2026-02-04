#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int k = 0; k < 8000; k++)
    for (int j = 0; j < 4; j++) {
        int idx = k * 4 + j;
        a[idx] = (idx * 7) % 32000;
    }
}
