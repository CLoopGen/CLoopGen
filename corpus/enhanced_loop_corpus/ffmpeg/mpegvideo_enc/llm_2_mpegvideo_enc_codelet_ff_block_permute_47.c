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
    // Variant 2 (corrected): Loop unrolling with for-loop only (no while/do-while), reducing effective loop depth via larger steps
    for (i = 0; i <= last; ) {  // Empty increment, manual update inside
        const int j = scantable[i];
        temp[j] = block[j];
        block[j] = 0;
        i++;

        if (i > last) break;

        const int j2 = scantable[i];
        temp[j2] = block[j2];
        block[j2] = 0;
        i++;

        if (i > last) break;

        const int j3 = scantable[i];
        temp[j3] = block[j3];
        block[j3] = 0;
        i++;

        if (i > last) break;

        const int j4 = scantable[i];
        temp[j4] = block[j4];
        block[j4] = 0;
        i++;
    }
}
