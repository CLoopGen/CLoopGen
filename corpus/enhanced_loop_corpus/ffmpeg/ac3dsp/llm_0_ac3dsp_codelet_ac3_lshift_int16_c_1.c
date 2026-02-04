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
        src32[i] = (src32[i] << shift) & mask;
        if (i + 1 < len) src32[i + 1] = (src32[i + 1] << shift) & mask;
        if (i + 2 < len) src32[i + 2] = (src32[i + 2] << shift) & mask;
        if (i + 3 < len) src32[i + 3] = (src32[i + 3] << shift) & mask;
    }
}
