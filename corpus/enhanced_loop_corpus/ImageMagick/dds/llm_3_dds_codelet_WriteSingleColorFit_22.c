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
    // Variant 2: Indirect memory access using a fixed offset map (reverse order access)
    const unsigned char mapping[16] = {15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
    for (i = 0; i < 16; i++) {
        indexes[mapping[i]] = index;
    }
}
