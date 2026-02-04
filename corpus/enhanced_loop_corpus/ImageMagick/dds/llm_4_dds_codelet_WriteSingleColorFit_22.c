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
    for (i = 0; i < 16; i++) {
        if (i % 4 != 0)
            continue;
        indexes[i] = index;
    }
}
