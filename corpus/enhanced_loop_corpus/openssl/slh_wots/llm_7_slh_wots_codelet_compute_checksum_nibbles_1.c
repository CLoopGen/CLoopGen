#include <stdio.h>

#include <inttypes.h>

extern  uint8_t *in;
extern size_t in_len;
extern size_t i;
extern uint16_t csum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t local_csum1 = 0, local_csum2 = 0;
    size_t unroll_factor = 2;
    size_t limit = in_len - (in_len % unroll_factor);

    for (i = 0; i < limit; i += unroll_factor) {
        local_csum1 += in[i];
        local_csum2 += in[i + 1];
    }
    for (; i < in_len; ++i)
        local_csum1 += in[i];

    csum += (local_csum1 + local_csum2);
}
