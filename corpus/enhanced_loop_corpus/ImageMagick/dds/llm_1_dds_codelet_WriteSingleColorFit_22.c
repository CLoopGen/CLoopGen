#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t i;
extern unsigned char _usr_index;
extern unsigned char indexes[16];

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    for (i = 0; i < 4; i++) {
        indexes[i * 4 + 0] = index;
        indexes[i * 4 + 1] = index;
        indexes[i * 4 + 2] = index;
        indexes[i * 4 + 3] = index;
    }
}
