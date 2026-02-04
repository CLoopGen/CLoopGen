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
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < subframe_size; i += 2)
        selected_signal[i] >>= -shift;
}
