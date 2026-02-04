#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *p;
extern int cc_count;
extern int i;
extern uint8_t field1;
extern uint8_t *cap;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with local accumulation before store
    uint8_t temp[6];
    for (i = 0; i < cc_count; i++) {
        temp[0] = (p[0] == 255 && field1) ? 252 : 253;
        temp[1] = p[1];
        temp[2] = p[2];
        temp[3] = (p[3] == 255 && !field1) ? 252 : 253;
        temp[4] = p[4];
        temp[5] = p[5];
        // Store consecutively in one block write
        __builtin_memcpy(cap, temp, 6);
        cap += 6;
        p += 6;
    }
}
