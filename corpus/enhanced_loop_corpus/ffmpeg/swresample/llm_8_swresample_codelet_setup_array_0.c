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
    int j;
    for (i = 0; i < 32; i++) {
        for (j = 0; j < 4; j++) {
            out[i * 4 + j] = in + (i * 4 + j) * plane_size;
        }
    }
}
