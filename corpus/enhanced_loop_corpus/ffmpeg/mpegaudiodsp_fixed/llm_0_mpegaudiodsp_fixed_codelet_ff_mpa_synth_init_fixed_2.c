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
    for (int k = 0; k < 128; k++) {
        int i = k / 16;
        int j = k % 16;
        window[512 + 128 + 16 * i + j] = window[64 * i + 48 - j];
    }
}
