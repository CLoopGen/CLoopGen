#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int window_offsets[32];
extern int window_offsets_size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16; ++i) {
    int val = window_offsets[i];
    if (val == 0)
        continue;
    window_offsets[window_offsets_size++] = val;
    window_offsets[window_offsets_size++] = val + 1;
    window_offsets[window_offsets_size++] = val - 1;
}
}
