#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t in;
extern  uint8_t *shuffle;
extern int shuffle_len;
extern int i;
extern uint64_t res;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t local_res = res;
    uint64_t local_in = in;
    for (i = 0; i < shuffle_len; i++) {
        uint8_t shift = *shuffle--;
        local_res ^= (local_in & 1) << shift; // Change from |= to ^= and create WAW-like dependency on local_res only
        local_in >>= 1;
    }
    res = local_res;
}
