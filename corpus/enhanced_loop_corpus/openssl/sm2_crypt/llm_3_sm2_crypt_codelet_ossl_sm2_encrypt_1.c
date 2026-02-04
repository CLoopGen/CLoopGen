#include <stdio.h>

#include <inttypes.h>

extern  uint8_t *msg;
extern size_t msg_len;
extern size_t i;
extern uint8_t *msg_mask;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (backward traversal)
    size_t i;
    for (i = msg_len; i != 0; --i) {
        msg_mask[i - 1] ^= msg[i - 1];
    }
}
