#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct GetByteContext {
    const uint8_t *buffer;
    const uint8_t *buffer_end;
    const uint8_t *buffer_start;
} GetByteContext;

extern GetByteContext gb;
extern int i;
extern int chunk_len;
extern uint16_t res;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (iterate backwards)
    for (i = chunk_len - 3; i >= 0; i--)
        res += gb.buffer[i];
}
