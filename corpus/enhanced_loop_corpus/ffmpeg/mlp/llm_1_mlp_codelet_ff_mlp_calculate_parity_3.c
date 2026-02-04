#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern uint32_t scratch;
extern  uint8_t *buf_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (uint8_t* temp_buf = buf; temp_buf < buf_end; temp_buf++) {
        for (uint32_t offset = 0; offset < 1; offset++) {
            scratch ^= *(temp_buf + offset);
        }
    }
}
