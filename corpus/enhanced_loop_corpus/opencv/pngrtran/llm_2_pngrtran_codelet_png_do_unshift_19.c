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
    int *shift_ptr = shift;
    for (c = have_shift = 0; c < channels; ++c, shift_ptr++) {
        if (*shift_ptr <= 0 || *shift_ptr >= bit_depth)
            *shift_ptr = 0;
        else
            have_shift = 1;
    }
}
