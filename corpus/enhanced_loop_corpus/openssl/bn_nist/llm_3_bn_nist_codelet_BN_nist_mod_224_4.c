#include <stdio.h>

#include <inttypes.h>

extern unsigned long c_d[4];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive backward traversal from a calculated bound
    // Adjust loop to run backwards using consecutive decrement
    int upper_bound = (224 + (8 * 8) - 1) / (8 * 8);
    for (; ii >= 0 && ii < upper_bound; --ii) {
        (c_d)[ii] = 0;
        if (ii == 0) break; // Prevent underflow by breaking at 0 after use
    }
    // Note: Assumes ii is initialized to upper_bound-1 before loop call for correctness
}
