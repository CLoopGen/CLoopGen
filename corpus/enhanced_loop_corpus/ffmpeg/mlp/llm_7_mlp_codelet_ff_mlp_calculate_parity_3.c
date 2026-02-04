#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern uint32_t scratch;
extern  uint8_t *buf_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *local_buf = buf;
    uint32_t local_scratch = scratch;
    for (ptrdiff_t offset = 0; local_buf + offset < buf_end; offset++) {
        local_scratch ^= *(local_buf + offset);
    }
    scratch = local_scratch;
}
