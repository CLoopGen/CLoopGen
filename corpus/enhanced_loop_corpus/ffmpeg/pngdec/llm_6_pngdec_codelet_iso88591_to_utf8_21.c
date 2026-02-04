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
    uint8_t temp;
    for (i = 0; i < size_in; i++) {
        temp = in[i];
        if (temp >= 128) {
            *(q++) = 192 | (temp >> 6);
            *(q++) = 128 | (temp & 63);
        } else {
            *(q++) = temp;
        }
    }
}
