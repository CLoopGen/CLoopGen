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
    int j;
    for (i = 0; i < subframe_size * 2; i += 2) {
        j = i < subframe_size ? i : subframe_size - 1;
        selected_signal[j] >>= -shift;
        if (i + 1 < subframe_size)
            selected_signal[i + 1] >>= -shift;
    }
}
