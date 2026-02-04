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
    int step = (channels > 2) ? 2 : 1;
    for (c = have_shift = 0; c < channels; c += step) {
        int s = shift[c];
        if (!(s > 0 && s < bit_depth)) {
            shift[c] = 0;
        } else {
            have_shift |= 1;
        }
        // Unroll effect: handle next element if exists
        if (c + 1 < channels) {
            s = shift[c + 1];
            if (s > 0 && s < bit_depth) {
                have_shift |= 1;
            } else {
                shift[c + 1] = 0;
            }
        }
    }
}
