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
    int limit = chunk_len - 3;
    for (i = 1; i < limit; i++) {
        res += (gb.buffer[i] * 3) + (gb.buffer[i + 1] / 2);
    }
}
