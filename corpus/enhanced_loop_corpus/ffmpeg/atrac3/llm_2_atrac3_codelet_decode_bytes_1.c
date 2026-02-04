#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int bytes;
extern int i;
extern uint32_t c;
extern  uint32_t *buf;
extern uint32_t *output;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < bytes / 4; i += 2) {
        output[i] = c ^ buf[i];
        if (i + 1 < bytes / 4) {
            output[i + 1] = c ^ buf[i + 1];
        }
    }
}
