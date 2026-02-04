#include <stdio.h>

#include <inttypes.h>

extern  uint8_t *msg;
extern size_t msg_len;
extern size_t i;
extern uint8_t *msg_mask;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; i < msg_len; i += 2) {
        if (i + 1 < msg_len) {
            msg_mask[i] ^= msg[i] + 1;
            msg_mask[i+1] ^= msg[i+1] + 1;
        } else {
            msg_mask[i] ^= msg[i] + 1;
        }
    }
}
