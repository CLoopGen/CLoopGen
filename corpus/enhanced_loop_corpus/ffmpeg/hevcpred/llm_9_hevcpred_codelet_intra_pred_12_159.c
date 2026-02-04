#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint16_t *left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 63; i++) {
    uint16_t term1 = (64 - (i + 1)) * left[-1];
    uint16_t term2 = (i + 1) * left[63];
    uint16_t sum = term1 + term2 + 32;
    left[i] = sum >> 6;
}
}
