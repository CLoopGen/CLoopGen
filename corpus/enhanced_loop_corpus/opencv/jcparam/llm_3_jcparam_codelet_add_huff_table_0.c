#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char UINT8;

extern  UINT8 *bits;
extern int nsymbols;
extern int len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to simulate a non-sequential access pattern
    const int indices[16] = {1,3,5,7,9,11,13,15,2,4,6,8,10,12,14,16}; // Odd indices first, then even
    for (len = 0; len < 16; len++) {
        nsymbols += bits[indices[len]];
    }
}
