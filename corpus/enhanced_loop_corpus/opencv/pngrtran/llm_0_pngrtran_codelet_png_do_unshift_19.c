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
    for (int i = 0; i < channels; ++i) {
        for (c = have_shift = 0; c < 1; ++c) {
            if (shift[i] <= 0 || shift[i] >= bit_depth)
                shift[i] = 0;
            else
                have_shift = 1;
        }
    }
}
