#include <stdio.h>

#include <inttypes.h>

extern  uint8_t *in;
extern int in_len;
extern uint64_t digit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *local_in = in;
    int stride = 2;
    int effective_len = (in_len + stride - 1) / stride;
    for (int i = 0; i < effective_len && (i * stride) < in_len; i++) {
        int idx = i * stride;
        digit <<= 8;
        digit += (uint64_t)(local_in[idx]);
    }
}
