#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *output;
extern int p1;
extern int i;
extern uint32_t pix32;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t **indirect_output = (uint8_t**)malloc(p1 * sizeof(uint8_t*));
    if (!indirect_output) return;
    for (i = 0; i < p1; i++) {
        indirect_output[i] = output + i * 4;
    }
    for (i = 0; i < p1; i++) {
        *(uint32_t *)indirect_output[i] = pix32;
    }
    free(indirect_output);
}
