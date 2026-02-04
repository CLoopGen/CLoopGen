#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory access with forward traversal
    // Ensures tight sequential access, typical in cache-friendly loops
    // Reset index to ensure valid range and use unit stride
    for (i = 2; i < length / 2 - 1; ++i) {
        // Simulated consecutive memory access (e.g., arr[i] = arr[i] * 2;)
    }
}
