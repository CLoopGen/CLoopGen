#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int x86_reg;

extern x86_reg i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern with stride of 8
    int arr[64];
    for (i = 0; i < 8; i++) {
        arr[i * 8] = i;  // Access every 8th element (strided access)
    }
}
