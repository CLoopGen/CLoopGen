#include <stdio.h>

#include <inttypes.h>

extern uint8_t *ptext_buf;
extern int i;
extern uint8_t *msg_mask;
extern  uint8_t *C2;
extern int msg_len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j != msg_len; ++j)
        for (i = j; i == j && i != msg_len; ++i)
            ptext_buf[i] = C2[i] ^ msg_mask[i];
}
