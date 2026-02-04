#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern uint32_t scratch;
extern  uint8_t *buf_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *temp = buf;
    for (; temp < buf_end && ((intptr_t)temp & 3); temp++) {
        if (((intptr_t)temp % 2) == 0)
            scratch ^= *temp;
    }
    buf = temp;
}
