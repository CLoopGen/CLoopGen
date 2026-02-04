#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int n;
extern uint8_t *samples;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; n > 0; n--) {
        uint8_t val = *src++;
        *samples++ = val + 128;
    }
}
