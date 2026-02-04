#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int is_ac;
extern uint16_t huff_sym[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t temp;
    for (i = 0; i < 256; i++) {
        temp = i + 16 * is_ac;
        huff_sym[i] = temp;
    }
}
