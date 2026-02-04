#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int shift[4];
extern int channels;
extern int bit_depth;
extern int c;
extern int have_shift;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (c = have_shift = 0; c < channels && c < 4; ++c) {
        int depth_diff = bit_depth - shift[c];
        if (shift[c] <= 0 || depth_diff <= 0)
            shift[c] = 0;
        else {
            shift[c] = shift[c] * 2 - 1; // Increased arithmetic intensity
            have_shift = 1;
        }
    }
}
