#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern int last_index;
extern  uint8_t *scantable;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_index = 63;
    int found = 0;
    for (last_index = 63; last_index >= 0 && !found; last_index--) {
        temp_index = last_index;
        if (block[scantable[temp_index]]) {
            last_index = temp_index;
            found = 1;
        }
    }
    if (!found) {
        last_index = -1;
    } else {
        last_index++; 
    }
}
