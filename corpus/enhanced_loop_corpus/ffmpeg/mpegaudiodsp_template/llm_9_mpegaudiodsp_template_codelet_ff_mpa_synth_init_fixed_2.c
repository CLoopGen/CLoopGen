#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t MPA_INT;

extern MPA_INT *window;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    MPA_INT offset_i = 16 * i;
    MPA_INT base_src = 64 * i + 48;
    MPA_INT base_dst = 512 + 128 + offset_i;
    for (j = 0; j < 16; j++) {
        MPA_INT temp = base_src - j;
        window[base_dst + j] = window[temp];
    }
}
}
