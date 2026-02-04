#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern  uint8_t *scantable;
extern  uint32_t *qmul;
extern int level[16];
extern int total_coeff;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i < total_coeff && i < 16; i += 2) {
        scantable--;
        int32_t val1 = ((int)(level[i] * qmul[*scantable] + 32)) >> 6;
        ((int32_t *)block)[*scantable] = val1;

        if (i + 1 < total_coeff) {
            uint8_t next_scan = *(scantable - 1);
            int32_t val2 = ((int)(level[i + 1] * qmul[next_scan] + 32)) >> 6;
            ((int32_t *)block)[next_scan] = val2;
            scantable--;
        }
    }
}
