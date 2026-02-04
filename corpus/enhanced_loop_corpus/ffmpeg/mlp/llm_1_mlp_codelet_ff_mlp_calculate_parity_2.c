#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern uint32_t scratch;
extern  uint8_t *buf_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 1 && buf < buf_end - 3; outer++)
        for (; buf < buf_end - 3; buf += 4)
            scratch ^= *((const uint32_t *)buf);
}
