#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern uint32_t scratch;
extern  uint8_t *buf_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse traversal with consecutive access from end to start
    for (uint8_t *ptr = buf_end - 1; ptr >= buf; ptr--)
        scratch ^= *ptr;
}
