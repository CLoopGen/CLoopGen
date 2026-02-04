#include <stdio.h>

#include <inttypes.h>

extern  uint8_t *msg;
extern size_t msg_len;
extern size_t i;
extern uint8_t *msg_mask;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; i != msg_len; ++i)
        for (j = 0; j < 1; ++j)
            msg_mask[i] ^= msg[i];
}
