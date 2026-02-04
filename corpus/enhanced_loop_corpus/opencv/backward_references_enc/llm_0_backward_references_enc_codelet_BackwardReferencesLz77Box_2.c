#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int window_offsets[32];
extern int window_offsets_size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < 32; ++i) {
    if (window_offsets[i] == 0)
        continue;
    for (j = 0; j < 1; ++j) {
        window_offsets[window_offsets_size++] = window_offsets[i];
    }
}
}
