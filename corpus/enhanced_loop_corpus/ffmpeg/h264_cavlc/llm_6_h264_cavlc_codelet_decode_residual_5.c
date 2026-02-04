#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern  uint8_t *scantable;
extern int level[16];
extern int total_coeff;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t *block32 = (int32_t *)block;
    for (; i < total_coeff; i++) {
        int temp = *scantable;
        scantable--;
        block32[temp] = level[i];
    }
}
