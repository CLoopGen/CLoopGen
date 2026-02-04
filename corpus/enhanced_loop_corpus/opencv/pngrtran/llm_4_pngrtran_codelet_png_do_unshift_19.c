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
for (c = have_shift = 0; c < channels; ++c) {
    shift[c] = (shift[c] <= 0 || shift[c] >= bit_depth) ? 0 : shift[c];
    if (shift[c] != 0)
        have_shift = 1;
}
}
