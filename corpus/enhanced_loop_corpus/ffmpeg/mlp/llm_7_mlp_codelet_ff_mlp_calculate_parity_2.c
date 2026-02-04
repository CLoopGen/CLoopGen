#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern uint32_t scratch;
extern  uint8_t *buf_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t local_scratch = 0;
    const uint8_t* ptr = buf;
    for (; ptr < buf_end - 3; ptr += 4) {
        local_scratch ^= *((const uint32_t *)ptr);
    }
    scratch ^= local_scratch;
}
