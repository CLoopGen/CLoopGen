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
    int base_src = 64 * i + 48;
    int base_dst = 640 + 16 * i;
    for (j = 0; j < 16; j++) {
        MPA_INT temp = window[base_src - j];
        window[base_dst + j] = temp;
    }
}
}
