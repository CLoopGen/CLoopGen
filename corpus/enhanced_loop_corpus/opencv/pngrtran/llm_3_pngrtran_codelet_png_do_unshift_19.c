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
    int indices[4] = {0, 1, 2, 3};
    for (c = have_shift = 0; c < channels; ++c) {
        int idx = indices[c]; // Indirect access via index array
        if (shift[idx] <= 0 || shift[idx] >= bit_depth)
            shift[idx] = 0;
        else
            have_shift = 1;
    }
}
