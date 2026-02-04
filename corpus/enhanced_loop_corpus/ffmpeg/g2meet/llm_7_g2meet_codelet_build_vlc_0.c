#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int is_ac;
extern uint16_t huff_sym[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    huff_sym[0] = 16 * is_ac;
    for (i = 1; i < 256; i++) {
        huff_sym[i] = huff_sym[i-1] + 1;
    }
}
