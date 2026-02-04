#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t stride;
extern int32_t height;
extern int8_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by precomputing the total offset
    int32_t total_offset = (height / 2) * 2 * stride;
    src += total_offset;
}
