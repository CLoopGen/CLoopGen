#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern int16_t dc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t local_block[16];
    int idx = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            local_block[idx++] = dc + i; // Introduce loop-carried dependency via 'i' and create RAW: j depends on i
        }
        if (i == 3) {
            for (j = 0; j < 16; j++) {
                block[j] = local_block[j]; // Final write to shared block after full computation
            }
        }
    }
    block += 16;
}
