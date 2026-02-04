#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int max_order;
extern double ref[32];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward traversal using temporary array-like behavior
    // Simulate a shift by processing elements from front to back using a sliding window
    double temp[32];
    for (i = 0; i < max_order; i++)
        temp[i] = ref[i];  // Copy to avoid data race in updates

    for (i = 1; i < max_order; i++)
        ref[i] = temp[i - 1] - ref[i];
}
