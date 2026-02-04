#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern uint32_t scratch;
extern  uint8_t *buf_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *ptr = buf;
    for (; ptr < buf_end; ptr++) {
        if (*ptr != 0) {
            scratch ^= *ptr;
        }
    }
}
