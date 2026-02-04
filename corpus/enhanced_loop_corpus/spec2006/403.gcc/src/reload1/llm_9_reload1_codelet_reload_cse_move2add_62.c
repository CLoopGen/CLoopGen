#include <stdio.h>

#include <inttypes.h>

extern int reg_set_luid[53];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with increased trip count via unrolling-like structure
    // Original loop unrolled into two sequential loops with simpler per-element assignment
    for (i = 53 - 1; i >= 27; i--)
        reg_set_luid[i] = 0;
    
    for (i = 26; i >= 0; i--)
        reg_set_luid[i] = 0;
}
