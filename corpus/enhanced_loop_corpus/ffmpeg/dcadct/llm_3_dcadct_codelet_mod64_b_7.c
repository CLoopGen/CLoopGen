#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *input;
extern int *output;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reversed access from the end of the input block
    for (i = 0; i < 16; i++) {
        int rev_idx = 15 - i;
        output[i] = input[rev_idx] + input[16 + rev_idx];
    }
}
