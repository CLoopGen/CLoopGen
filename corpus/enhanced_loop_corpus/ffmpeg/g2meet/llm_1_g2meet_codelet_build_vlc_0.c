#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int is_ac;
extern uint16_t huff_sym[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 256; i += 4) {
        huff_sym[i] = i + 16 * is_ac;
        if (i + 1 < 256) huff_sym[i + 1] = (i + 1) + 16 * is_ac;
        if (i + 2 < 256) huff_sym[i + 2] = (i + 2) + 16 * is_ac;
        if (i + 3 < 256) huff_sym[i + 3] = (i + 3) + 16 * is_ac;
    }
}
