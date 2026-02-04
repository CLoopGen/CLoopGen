#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int window_offsets[32];
extern int window_offsets_size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[32];
    int temp_size = 0;
    for (i = 0; i < 32; ++i) {
        if (window_offsets[i] == 0)
            continue;
        temp[temp_size++] = window_offsets[i];
    }
    for (i = 0; i < temp_size; ++i) {
        window_offsets[window_offsets_size + i] = temp[i];
    }
    window_offsets_size += temp_size;
}
