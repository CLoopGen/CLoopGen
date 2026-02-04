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
    for (j = 0; j < msg_len; j += 2) {
        ptext_buf[j] = C2[j] ^ msg_mask[j];
        if (j + 1 < msg_len) {
            ptext_buf[j + 1] = C2[j + 1] ^ msg_mask[j + 1];
        }
    }
}
