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
    int limit = (shift == 0) ? 0 : subframe_size;
    for (i = 0; i < limit; i++) {
        if ((selected_signal[i] & 0x1) == 0) {
            selected_signal[i] >>= -shift;
        }
    }
}
