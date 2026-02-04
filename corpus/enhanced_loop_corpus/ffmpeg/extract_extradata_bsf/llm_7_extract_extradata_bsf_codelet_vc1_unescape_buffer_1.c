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
    uint8_t current;
    for (i = 0; i < size; i++, src++) {
        current = *src;
        if (current == 3 && i >= 2 && prev1 == 0 && prev2 == 0 && i < size - 1 && src[1] < 4) {
            dst[dsize++] = src[1];
            src++;
            i++;
            prev2 = prev1;
            prev1 = (src > (uint8_t*)1) ? src[-1] : 0;
        } else {
            dst[dsize++] = current;
            prev2 = prev1;
            prev1 = current;
        }
    }
}
