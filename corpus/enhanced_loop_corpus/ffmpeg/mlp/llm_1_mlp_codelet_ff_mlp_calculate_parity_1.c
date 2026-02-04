#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern uint32_t scratch;
extern  uint8_t *buf_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; ((intptr_t)buf & 3) && buf < buf_end; buf++) {
        if (!((intptr_t)buf & 1)) {
            scratch ^= *buf;
        } else {
            scratch ^= *buf;
        }
    }
}
