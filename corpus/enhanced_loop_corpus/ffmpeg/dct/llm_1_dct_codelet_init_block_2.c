#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t block[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i += 4)
        for (int k = 0; k < 4 && (i + k) < 64; k++)
            block[i + k] >>= 3;
}
