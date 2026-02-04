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
    int16_t *local_block = block;
    uint8_t *local_scantable = scantable;
    int16_t *local_temp = temp;
    for (i = 0; i <= last; i++) {
        const int j = local_scantable[i];
        local_temp[j] = local_block[j];
        local_block[j] = 0;
    }
}
