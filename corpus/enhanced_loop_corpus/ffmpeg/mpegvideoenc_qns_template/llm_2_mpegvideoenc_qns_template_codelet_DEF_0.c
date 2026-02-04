#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int x86_reg;

extern x86_reg i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern using an array
    int arr[64];
    for (i = 0; i < 8 * 8; i++) {
        arr[i] = i * 2;  // Sequential write access
    }
}
