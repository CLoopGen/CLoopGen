#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int size;
extern uint8_t *dst;
extern int dsize;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t prev1 = 0, prev2 = 0;
    for (i = 0; i < size; i++, src++) {
        uint8_t current = *src;
        if (current == 3 && i >= 2 && !prev1 && !prev2 && i < size - 1) {
            uint8_t next_val = src[1];
            if (next_val < 4) {
                dst[dsize++] = next_val;
                src++;
                i++;
                prev2 = prev1;
                prev1 = 0;
                continue;
            }
        }
        dst[dsize++] = current;
        prev2 = prev1;
        prev1 = current;
    }
}
