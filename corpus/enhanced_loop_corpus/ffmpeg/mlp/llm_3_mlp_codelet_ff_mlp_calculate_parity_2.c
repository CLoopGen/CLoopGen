#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern uint32_t scratch;
extern  uint8_t *buf_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with stride of 8 bytes (every 8th byte starting from offset)
    for (size_t offset = 0; buf + offset < buf_end - 3; offset += 8)
        scratch ^= *((const uint32_t *)(buf + offset));
}
