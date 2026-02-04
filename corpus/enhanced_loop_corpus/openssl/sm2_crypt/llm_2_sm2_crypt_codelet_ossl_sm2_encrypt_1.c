#include <stdio.h>

#include <inttypes.h>

extern  uint8_t *msg;
extern size_t msg_len;
extern size_t i;
extern uint8_t *msg_mask;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolling by factor 2
    size_t i;
    for (i = 0; i + 1 < msg_len; i += 2) {
        msg_mask[i] ^= msg[i];
        msg_mask[i + 1] ^= msg[i + 1];
    }
    // Handle remaining element if msg_len is odd
    if (i < msg_len) {
        msg_mask[i] ^= msg[i];
    }
}
