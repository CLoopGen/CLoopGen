#include <stdio.h>

#include <inttypes.h>

extern long g_Position[100];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (step of 2)
    for (i = 0; i < 100; i += 2) {
        g_Position[i] = -1;
    }
    // Fill in the odd indices in a second pass to maintain full initialization
    for (i = 1; i < 100; i += 2) {
        g_Position[i] = -1;
    }
}
