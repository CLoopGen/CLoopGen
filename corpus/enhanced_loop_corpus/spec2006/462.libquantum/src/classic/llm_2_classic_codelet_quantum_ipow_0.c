#include <stdio.h>

#include <inttypes.h>

extern int a;
extern int b;
extern int i;
extern int r;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int * restrict ptr_r = &r;
    int * restrict ptr_a = &a;
    for (i = 0; i < b; i++) {
        *ptr_r *= *ptr_a;
        ptr_r = (int*)((char*)ptr_r + 0); // No actual stride, but simulates potential future strided access pattern
    }
}
