#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int is_ac;
extern uint16_t huff_sym[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < 512; i += 2) {
    huff_sym[i] = i + 16 * is_ac;
    if (i + 1 < 256) {
        huff_sym[i + 1] = i + 1 + 16 * is_ac;
    }
}
}
