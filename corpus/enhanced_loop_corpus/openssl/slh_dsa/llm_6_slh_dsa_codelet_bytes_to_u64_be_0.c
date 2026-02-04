#include <stdio.h>

#include <inttypes.h>

extern  uint8_t *in;
extern size_t in_len;
extern size_t i;
extern uint64_t total;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t local_total = total;
    for (i = 0; i < in_len; i++) {
        local_total = (local_total << 8) | *(in + i);
    }
    total = local_total;
}
