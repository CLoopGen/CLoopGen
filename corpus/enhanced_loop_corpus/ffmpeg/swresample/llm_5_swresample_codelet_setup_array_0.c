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
    for (i = 0; i < 32; i++) {
        out[i] = in + i * plane_size;
        if (i == 15) {
            i += 2; // Skip next two iterations after reaching midpoint
        }
    }
}
