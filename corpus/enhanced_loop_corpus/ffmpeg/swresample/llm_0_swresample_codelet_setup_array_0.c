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
    int j, k;
    for (j = 0; j < 8; j++) {
        for (k = 0; k < 4; k++) {
            int i = j * 4 + k;
            out[i] = in + i * plane_size;
        }
    }
}
