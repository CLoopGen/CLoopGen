#include <stdio.h>

#include <inttypes.h>

extern  uint8_t *msg;
extern size_t msg_len;
extern size_t i;
extern uint8_t *msg_mask;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (msg_len > 0) {
        for (i = 0; i != msg_len; ++i)
            msg_mask[i] ^= msg[i];
    }
}
