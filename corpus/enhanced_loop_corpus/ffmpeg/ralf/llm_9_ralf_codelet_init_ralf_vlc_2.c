#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int counts[17];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with simplified operations and stride-based access
    for (i = 0; i <= 8; i += 2) {
        counts[i] = (i + 1) * (i + 1);
    }
}
