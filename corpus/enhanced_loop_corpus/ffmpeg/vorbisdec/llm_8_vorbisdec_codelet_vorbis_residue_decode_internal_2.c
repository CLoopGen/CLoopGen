#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int ch;
extern uint8_t *do_not_decode;
extern unsigned int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 1; j < ch && ch > 1; j += 2) {
        if (j + 1 < ch) {
            do_not_decode[0] &= (do_not_decode[j] | do_not_decode[j + 1]);
        } else {
            do_not_decode[0] &= do_not_decode[j];
        }
    }
}
