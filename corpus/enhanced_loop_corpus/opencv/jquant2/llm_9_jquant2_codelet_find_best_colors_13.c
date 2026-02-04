#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

extern int i;
extern JLONG *bptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Higher trip count with minimal arithmetic per iteration (lightweight computation)
    // The original trip count is increased using a larger shift-based calculation
    int trip_count = (1 << (5 - 2)) * (1 << (6 - 2)) + (1 << (5 - 2)); // Larger than original
    for (i = trip_count - 1; i >= 0; i--) {
        *bptr++ = 2147483647L; // Simple assignment, no extra operations
    }
}
