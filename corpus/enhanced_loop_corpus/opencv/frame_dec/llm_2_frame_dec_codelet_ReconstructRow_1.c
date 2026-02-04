#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[16] = {0}; // Local array for memory access
    for (j = 0; j < 8; ++j) {
        arr[j * 2] = j; // Strided access with step 2
    }
}
