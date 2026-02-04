#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern uint8_t *iv;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse sequential access — traverse arrays from last to first element
    for (i = 15; i >= 0; i--) {
        dst[i] = src[i] ^ iv[i];
    }
}
