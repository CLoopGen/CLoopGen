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
    for (i = 0; i < len; i += 8) {
        if (!(i & 7)) {
            src32[i] = (src32[i] << shift) & mask;
        }
        src32[i + 1] = (src32[i + 1] << shift) & mask;
        src32[i + 2] = (src32[i + 2] << shift) & mask;
        src32[i + 3] = (src32[i + 3] << shift) & mask;
        src32[i + 4] = (src32[i + 4] << shift) & mask;
        src32[i + 5] = (src32[i + 5] << shift) & mask;
        src32[i + 6] = (src32[i + 6] << shift) & mask;
        src32[i + 7] = (src32[i + 7] << shift) & mask;
    }
}
