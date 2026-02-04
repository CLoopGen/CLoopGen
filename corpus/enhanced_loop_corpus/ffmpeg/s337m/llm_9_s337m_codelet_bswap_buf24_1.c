#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *data;
extern int size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = (size / 3) * 3;
    for (i = 0; i < limit; i += 3) {
        uint8_t SWAP_tmp = data[i + 2];
        ((uint8_t*)data)[i + 2] = ((uint8_t*)data)[i];
        ((uint8_t*)data)[i] = SWAP_tmp;
    }
}
