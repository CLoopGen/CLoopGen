#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int is_ac;
extern uint16_t huff_sym[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            int idx = i * 16 + j;
            huff_sym[idx] = idx + 16 * is_ac;
        }
    }
}
