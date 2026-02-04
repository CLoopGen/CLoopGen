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
    uint8_t local_pix[3] = {pix[0], pix[1], pix[2]};
    for (i = 0; i < p1; i += 3) {
        *(uint32_t*)output = *(uint32_t*)local_pix;
        output += 3;
        if (i + 1 < p1) {
            *(uint32_t*)output = *(uint32_t*)local_pix;
            output += 3;
        }
        if (i + 2 < p1) {
            *(uint32_t*)output = *(uint32_t*)local_pix;
            output += 3;
        }
    }
}
