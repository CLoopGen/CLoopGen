#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int window_offsets[32];
extern int window_offsets_size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 32; ++i) {
        window_offsets_size += (window_offsets[i] != 0);
        if (window_offsets[i] != 0) {
            window_offsets[window_offsets_size - 1] = window_offsets[i];
        }
    }
}
