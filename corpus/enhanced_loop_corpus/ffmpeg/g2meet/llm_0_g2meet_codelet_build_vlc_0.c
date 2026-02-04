#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int is_ac;
extern uint16_t huff_sym[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 16; outer++) {
        for (i = outer * 16; i < (outer + 1) * 16 && i < 256; i++) {
            huff_sym[i] = i + 16 * is_ac;
        }
    }
}
