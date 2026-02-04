#include <stdio.h>

#include <inttypes.h>

extern  uint8_t *msg;
extern size_t msg_len;
extern size_t i;
extern uint8_t *msg_mask;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t unroll_factor = 4;
    size_t remainder = msg_len % unroll_factor;
    size_t limit = msg_len - remainder;

    for (i = 0; i < limit; i += unroll_factor) {
        msg_mask[i] ^= msg[i];
        msg_mask[i+1] ^= msg[i+1];
        msg_mask[i+2] ^= msg[i+2];
        msg_mask[i+3] ^= msg[i+3];
    }

    for (; i < msg_len; ++i) {
        msg_mask[i] ^= msg[i];
    }
}
