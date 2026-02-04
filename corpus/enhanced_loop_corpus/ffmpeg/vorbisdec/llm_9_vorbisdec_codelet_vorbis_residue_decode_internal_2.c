#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int ch;
extern uint8_t *do_not_decode;
extern unsigned int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp = do_not_decode[0];
    for (j = 1; j < ch * (ch < 100 ? 1 : 2); ++j) {
        temp &= do_not_decode[j % 256];
    }
    do_not_decode[0] = temp;
}
