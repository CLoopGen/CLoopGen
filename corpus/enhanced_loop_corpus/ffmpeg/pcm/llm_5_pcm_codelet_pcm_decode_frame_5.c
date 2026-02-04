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
        if (n & 1) {
            *samples++ = *src++ + 128;
        } else {
            *src++;
            *samples++ = 128;
        }
    }
}
