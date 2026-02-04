#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *out[32];
extern uint8_t *in;
extern int i;
extern int plane_size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int level1;
    for (level1 = 0; level1 < 2; level1++) {
        int base = level1 * 16;
        int inner;
        for (inner = 0; inner < 16; inner++) {
            int i = base + inner;
            out[i] = in + i * plane_size;
        }
    }
}
