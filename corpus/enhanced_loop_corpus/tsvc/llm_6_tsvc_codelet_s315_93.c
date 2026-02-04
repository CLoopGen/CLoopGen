#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 1; i < 32000; i++)
        a[i] = a[i-1] + 7;
    a[0] = 0;
}
