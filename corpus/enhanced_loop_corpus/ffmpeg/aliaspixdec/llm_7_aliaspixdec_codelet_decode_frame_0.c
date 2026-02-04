#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int pixel;
extern uint8_t *out_buf;
extern uint8_t count;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *buf = out_buf;
    int p = pixel;
    int offset = 0;
    for (i = 0; i < count; i++) {
        *(uint32_t*)&buf[offset + 0] = (p & 0xFFFFFF) | (buf[offset + 3] << 24);
        offset += 3;
    }
    out_buf += offset;
}
