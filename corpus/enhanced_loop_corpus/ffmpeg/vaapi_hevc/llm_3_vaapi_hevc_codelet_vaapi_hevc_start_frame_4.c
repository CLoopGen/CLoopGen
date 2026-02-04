#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern with stride of 6 across a larger array
    int arr[2304]; // 6 * 64 * 6 to allow strided access without overflow
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 64; j++) {
            int index = j * 6 + i; // Strided access: step by 6 (transpose-like indexing)
            arr[index] = index;
        }
    }
}
