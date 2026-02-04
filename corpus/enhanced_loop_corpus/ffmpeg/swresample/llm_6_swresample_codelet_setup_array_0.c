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
    uint8_t **temp_out = out;
    uint8_t *base_in = in;
    int size = plane_size;
    for (i = 0; i < 32; i++) {
        temp_out[i] = base_in + i * size;
    }
}
