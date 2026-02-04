#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int subframe_size;
extern int i;
extern int16_t shift;
extern int16_t *selected_signal;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = (shift > 0) ? 1 : 2;
    for (i = 0; i < subframe_size; i += stride) {
        selected_signal[i] >>= -shift;
        selected_signal[i] += (selected_signal[i] & 1); // Add one arithmetic operation per iteration
    }
}
