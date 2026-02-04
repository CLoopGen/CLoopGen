#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *output;
extern int p1;
extern int i;
extern uint8_t pix[3];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < p1 * 3; i += 3) {
        *output++ = pix[0];
        *output++ = pix[1];
        *output++ = pix[2];
    }
}
