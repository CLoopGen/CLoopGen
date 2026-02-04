#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int len;
extern unsigned int shift;
extern uint32_t *src32;
extern  uint32_t mask;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i += 4) {
        uint32_t temp0 = (src32[i] << shift) & mask;
        uint32_t temp1 = (src32[i + 1] << shift) & mask;
        src32[i] = temp0;
        src32[i + 1] = temp1;
        if (i + 2 < len) {
            uint32_t temp2 = (src32[i + 2] << shift) & mask;
            uint32_t temp3 = (src32[i + 3] << shift) & mask;
            src32[i + 2] = temp2;
            src32[i + 3] = temp3;
        }
    }
}
