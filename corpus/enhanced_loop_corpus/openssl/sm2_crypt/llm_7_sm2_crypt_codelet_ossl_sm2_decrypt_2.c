#include <stdio.h>

#include <inttypes.h>

extern uint8_t *ptext_buf;
extern int i;
extern uint8_t *msg_mask;
extern  uint8_t *C2;
extern int msg_len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *buf = ptext_buf;
    const uint8_t *c2 = C2;
    const uint8_t *mask = msg_mask;
    int len = msg_len;
    for (i = 0; i < len; ++i)
        buf[i] = c2[i] ^ mask[i] ^ buf[(i + 1) % len]; // Introduces WAW and RAW loop-carried dependency via buf use
}
