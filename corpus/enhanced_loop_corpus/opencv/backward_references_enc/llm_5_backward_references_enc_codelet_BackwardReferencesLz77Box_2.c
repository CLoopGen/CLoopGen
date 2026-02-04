#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int window_offsets[32];
extern int window_offsets_size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_value;
    for (i = 0; i < 32; ++i) {
        temp_value = window_offsets[i];
        if (temp_value == 0) {
            continue;
        }
        window_offsets[window_offsets_size] = temp_value;
        window_offsets_size++;
    }
}
