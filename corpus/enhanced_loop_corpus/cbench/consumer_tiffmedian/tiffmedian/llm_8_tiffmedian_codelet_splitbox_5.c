#include <stdio.h>

#include <inttypes.h>

extern int first;
extern int last;
extern int *histp;
extern int i;
extern int sum;
extern int sum2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations and reduced trip count
    // Trip count is effectively halved by incrementing i by 2 each iteration, but each iteration performs more work.
    for (i = first; i <= last && (sum += *histp++) < sum2; ++i) {
        sum += (*histp - *(histp - 1)) * 2;  // Additional computation: difference of consecutive histogram values scaled
        ++i;  // Effectively process two elements per logical iteration
    }
}
