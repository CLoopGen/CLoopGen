#include <stdio.h>

#include <inttypes.h>

extern uint8_t *ptext_buf;
extern int i;
extern uint8_t *msg_mask;
extern  uint8_t *C2;
extern int msg_len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (msg_len <= 0) return;
    for (i = 0; i < msg_len; ++i)
        ptext_buf[i] = C2[i] ^ msg_mask[i];
}
