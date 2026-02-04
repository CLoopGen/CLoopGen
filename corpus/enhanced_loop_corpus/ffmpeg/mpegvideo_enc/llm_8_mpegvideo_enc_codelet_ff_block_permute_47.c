#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern  uint8_t *scantable;
extern int last;
extern int i;
extern int16_t temp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = last; i >= 0; i--) {
        const int j = scantable[i];
        const int16_t val = block[j];
        temp[j] = val;
        block[j] = val - val; // WAW and RAW dependency introduced via intermediate variable usage and arithmetic identity
    }
}
