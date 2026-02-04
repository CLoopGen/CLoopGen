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
    int step = (shift > 0) ? shift : 1;
    for (i = 0; i < subframe_size; i += step) {
        int16_t factor = 1 << (shift & 15);
        selected_signal[i] = (int16_t)(selected_signal[i] * factor);
    }
}
