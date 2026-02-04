#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t block[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i += 4) {
        block[i] >>= 3;
        block[i + 1] >>= 3;
        block[i + 2] >>= 3;
        block[i + 3] >>= 3;
    }
}
