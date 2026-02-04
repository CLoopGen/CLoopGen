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
    size_t j = 0;
    for (i = 0; i < size_in; i++) {
        if (in[i] >= 128) {
            for (j = 0; j < 2; j++) {
                if (j == 0) {
                    *(q++) = 192 | (in[i] >> 6);
                } else {
                    *(q++) = 128 | (in[i] & 63);
                }
            }
        } else {
            *(q++) = in[i];
        }
    }
}
