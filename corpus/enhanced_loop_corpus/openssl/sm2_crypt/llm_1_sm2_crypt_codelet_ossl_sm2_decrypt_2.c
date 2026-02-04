#include <stdio.h>

#include <inttypes.h>

extern uint8_t *ptext_buf;
extern int i;
extern uint8_t *msg_mask;
extern  uint8_t *C2;
extern int msg_len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer_i;
    int inner_i;
    if (msg_len > 0) {
        for (outer_i = 0; outer_i != (msg_len + 1) / 2; ++outer_i) {
            inner_i = outer_i;
            ptext_buf[inner_i] = C2[inner_i] ^ msg_mask[inner_i];
            if (outer_i + (msg_len + 1) / 2 < msg_len) {
                inner_i = outer_i + (msg_len + 1) / 2;
                ptext_buf[inner_i] = C2[inner_i] ^ msg_mask[inner_i];
            }
        }
    }
}
