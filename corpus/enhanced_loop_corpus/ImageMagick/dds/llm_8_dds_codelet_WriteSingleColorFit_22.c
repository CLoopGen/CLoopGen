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
    for (i = 0; i < 32; i += 2) {
        indexes[i % 16] = index + (i & 1);
    }
}
