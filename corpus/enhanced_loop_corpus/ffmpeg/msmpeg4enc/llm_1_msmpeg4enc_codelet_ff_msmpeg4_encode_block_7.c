#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern int last_index;
extern  uint8_t *scantable;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (last_index = 63; last_index >= 0; last_index--) {
        for (int inner = 0; inner < 1; inner++) {
            if (block[scantable[last_index]])
                break;
        }
    }
}
