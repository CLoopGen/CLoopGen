#include <stdio.h>

#include <inttypes.h>

extern uint8_t *ptext_buf;
extern int i;
extern uint8_t *msg_mask;
extern  uint8_t *C2;
extern int msg_len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *indices = (int*)__builtin_alloca(msg_len * sizeof(int));
    for (int idx = 0; idx < msg_len; ++idx)
        indices[idx] = idx;
    for (int k = 0; k < msg_len; ++k) {
        int i = indices[k];
        ptext_buf[i] = C2[i] ^ msg_mask[i];
    }
}
