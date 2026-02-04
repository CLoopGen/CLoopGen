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
    for (i = 0; i < 16; i += 2) {
        out[i]     = in + i       * plane_size;
        out[i + 1] = in + (i + 1) * plane_size;
    }
}
