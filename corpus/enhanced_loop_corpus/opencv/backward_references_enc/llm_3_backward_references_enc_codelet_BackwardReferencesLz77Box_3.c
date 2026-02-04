#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int window_offsets[32];
extern int window_offsets_new[32];
extern int window_offsets_size;
extern int window_offsets_new_size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < window_offsets_size; ++i) {
    int j;
    int is_reachable = 0;
    for (j = 0; j < window_offsets_size && !is_reachable; j += 2) {
        int index = j;
        if (index >= window_offsets_size) break;
        is_reachable |= (window_offsets[i] == window_offsets[index] + 1);
    }
    if (!is_reachable) {
        window_offsets_new[window_offsets_new_size] = window_offsets[i];
        ++window_offsets_new_size;
    }
}
}
