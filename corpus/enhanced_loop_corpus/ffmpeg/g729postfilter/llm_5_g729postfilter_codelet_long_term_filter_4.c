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
    int factor = 1 << shift;
    for (i = 0; i < subframe_size; i++) {
        if (selected_signal[i] != 0) {
            selected_signal[i] *= factor;
        }
    }
}
