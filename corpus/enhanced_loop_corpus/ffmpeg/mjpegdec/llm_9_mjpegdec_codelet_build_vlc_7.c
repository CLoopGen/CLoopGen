#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int is_ac;
extern uint16_t huff_sym[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 128; i++) {
    huff_sym[2*i] = 2*i + 16 * is_ac;
    huff_sym[2*i + 1] = 2*i + 1 + 16 * is_ac;
}
}
