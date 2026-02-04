#include <stdio.h>

#include <inttypes.h>

extern  uint8_t *in;
extern size_t in_len;
extern size_t i;
extern uint64_t total;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp = 0;
    for (i = 0; i < in_len; i++) {
        temp ^= (uint64_t)*(in + i) << ((i % 8) * 8);
    }
    total = (total << (in_len * 8 % 64)) ^ temp;
}
