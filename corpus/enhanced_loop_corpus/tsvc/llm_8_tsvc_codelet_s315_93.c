#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 16000; i++) {
        a[2*i] = (i * 7) % 32000;
        a[2*i + 1] = ((i + 1) * 9) % 32000;
    }
}
