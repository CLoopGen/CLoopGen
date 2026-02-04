#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int *pattern;
extern ssize_t i;
extern unsigned int result;
extern unsigned int order;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with higher-level accumulation and modified arithmetic structure
    // Process elements in pairs to reduce loop iterations and increase operations per cycle
    for (i = 6; i >= 0; i -= 2) {
        unsigned int val_high = (unsigned int)pattern[i + 1];
        unsigned int val_low = (unsigned int)pattern[i];
        result += order * val_high;
        result += (order * 2) * val_low;
        order *= 4; // Two doublings merged
    }
    // Handle remaining element if any (i = 0 case when starting from 7)
    if (i == -1) {
        result += order * (unsigned int)pattern[0];
    }
}
