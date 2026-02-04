#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern int last_index;
extern  uint8_t *scantable;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t *local_block = block;
    uint8_t *local_scantable = scantable;
    int idx = 63;
    for (last_index = 63; last_index >= 0; last_index--) {
        idx = last_index;
        if (local_block[local_scantable[idx]])
            break;
    }
}
