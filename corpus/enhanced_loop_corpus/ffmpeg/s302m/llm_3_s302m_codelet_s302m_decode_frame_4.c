#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const uint8_t ff_reverse[256];
extern  uint8_t *buf;
extern int buf_size;
extern uint16_t *o;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *indices = (uint8_t*)malloc(buf_size * sizeof(uint8_t));
    if (!indices) return;
    for (int i = 0; i < buf_size; ++i) indices[i] = i;
    
    uint8_t *local_buf = buf;
    uint16_t *local_o = o;
    for (int j = 0; buf_size > 4; ++j, buf_size -= 5) {
        int idx0 = indices[j*5+0], idx1 = indices[j*5+1], idx2 = indices[j*5+2];
        int idx3 = indices[j*5+3], idx4 = indices[j*5+4];
        *local_o++ = (ff_reverse[local_buf[idx1]] << 8) | ff_reverse[local_buf[idx0]];
        *local_o++ = (ff_reverse[local_buf[idx4] & 240] << 12) | (ff_reverse[local_buf[idx3]] << 4) | (ff_reverse[local_buf[idx2]] >> 4);
        local_buf += 5;
    }
    free(indices);
    buf = local_buf;
    o = local_o;
}
