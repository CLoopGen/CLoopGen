#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern uint32_t scratch;
extern  uint8_t *buf_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp = scratch;
    for (; buf + 3 < buf_end; buf += 4) {
        temp ^= *buf;
        temp ^= *(buf + 1);
        temp ^= *(buf + 2);
        temp ^= *(buf + 3);
    }
    for (; buf < buf_end; buf++) {
        temp ^= *buf;
    }
    scratch = temp;
}
