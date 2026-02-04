#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int n;
extern uint8_t *samples;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp;
    for (; n > 0; n--) {
        temp = *src++ + 128;
        *samples++ = temp;
    }
}
