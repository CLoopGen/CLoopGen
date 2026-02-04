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
    for (i = 0; i < shuffle_len; i++) {
        uint8_t bit = (in >> shuffle[i]) & 1;
        local_res += local_res + bit;
    }
    res = local_res;
}
