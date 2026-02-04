#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *in;
extern size_t size_in;
extern size_t i;
extern uint8_t *q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < size_in; i++) {
        uint8_t val = in[i];
        uint8_t is_high = (val >= 128);
        if (is_high) {
            *(q++) = 192 | (val >> 6);
            *(q++) = 128 | (val & 63);
        } else {
            *(q++) = val;
        }
    }
}
