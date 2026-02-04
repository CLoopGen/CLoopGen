#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int j = 0; j < 320; j++)
    for (int i = 0; i < 100; i++) {
        int idx = j * 100 + i;
        a[idx] = (idx * 7) % 32000;
    }
}
