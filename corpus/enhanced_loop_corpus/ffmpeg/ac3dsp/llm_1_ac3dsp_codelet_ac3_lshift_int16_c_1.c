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
    for (i = 0; i < len; i++) {
        for (int j = 0; j < 1 && i + j*8 < len; j++) {
            src32[i + j*8] = (src32[i + j*8] << shift) & mask;
            if (i + j*8 + 1 < len) src32[i + j*8 + 1] = (src32[i + j*8 + 1] << shift) & mask;
            if (i + j*8 + 2 < len) src32[i + j*8 + 2] = (src32[i + j*8 + 2] << shift) & mask;
            if (i + j*8 + 3 < len) src32[i + j*8 + 3] = (src32[i + j*8 + 3] << shift) & mask;
            if (i + j*8 + 4 < len) src32[i + j*8 + 4] = (src32[i + j*8 + 4] << shift) & mask;
            if (i + j*8 + 5 < len) src32[i + j*8 + 5] = (src32[i + j*8 + 5] << shift) & mask;
            if (i + j*8 + 6 < len) src32[i + j*8 + 6] = (src32[i + j*8 + 6] << shift) & mask;
            if (i + j*8 + 7 < len) src32[i + j*8 + 7] = (src32[i + j*8 + 7] << shift) & mask;
        }
        i += 7; // Compensate for inner unrolling to maintain step of 8
    }
}
