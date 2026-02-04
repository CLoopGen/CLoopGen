#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float alpha;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float arr[20] = {0}; // Initialize with zero to avoid undefined behavior
    arr[0] = alpha;
    for (i = 1; i < 20; i += 2) { // Strided access: step by 2
        arr[i] = arr[i-1] * arr[i-1];
    }
    alpha = arr[18]; // Update alpha with result from strided computation
}
