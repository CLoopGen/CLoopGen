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
    MPA_INT offset1 = 512 + 16 * i;
    MPA_INT offset2 = 64 * i + 32;
    for (j = 0; j < 16; j++) {
        window[offset1 + j] = window[offset2 - j];
        window[offset1 + j + 1] = window[offset2 - j - 1];
    }
}
}
