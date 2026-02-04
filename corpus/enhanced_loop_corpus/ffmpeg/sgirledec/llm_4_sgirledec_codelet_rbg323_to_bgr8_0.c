#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < size; i++) {
        uint8_t val = src[i];
        uint8_t temp = (((val << 3) & 192) | ((val << 3) & 56) | ((val >> 5) & 7));
        if ((val & 1)) {
            dst[i] = temp;
        } else {
            dst[i] = temp ^ 0xFF;
        }
    }
}
