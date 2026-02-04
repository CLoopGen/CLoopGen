#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *bits;
extern uint32_t exit_at_level[33];
extern unsigned int i;
extern unsigned int p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (bits[p] > 16 ? 16 : bits[p]); ++i) {
        uint32_t shifted_val = 1U << i;
        exit_at_level[i + 1] = shifted_val;
        if (i % 2 == 0) {
            exit_at_level[i + 2] = shifted_val << 1;
        }
    }
}
