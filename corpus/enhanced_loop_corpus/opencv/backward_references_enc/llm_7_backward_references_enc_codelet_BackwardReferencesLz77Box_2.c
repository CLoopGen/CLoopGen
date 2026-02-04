#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int window_offsets[32];
extern int window_offsets_size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int read_value, write_index;
    for (i = 0; i < 32; ++i) {
        read_value = window_offsets[i];
        if (read_value == 0)
            continue;
        write_index = window_offsets_size;
        window_offsets[write_index] = read_value;
        window_offsets_size = write_index + 1;
    }
}
