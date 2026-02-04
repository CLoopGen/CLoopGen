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
    for (i = 15; i >= 0; i--) {
        indexes[i] = index ^ (index << 1) ^ (i % 4);
    }
}
