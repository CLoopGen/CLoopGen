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
    int offset = -shift;
    int16_t prev = 0;
    for (i = 0; i < subframe_size; i++) {
        int16_t current = selected_signal[i];
        selected_signal[i] = current >> offset;
        prev = current; // Introduce WAW and RAW loop-carried dependency via 'prev'
    }
}
