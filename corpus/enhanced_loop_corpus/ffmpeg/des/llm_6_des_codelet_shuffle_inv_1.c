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
    res = 0;
    uint64_t temp_in = in;
    for (i = 0; i < shuffle_len; i++) {
        uint8_t idx = *shuffle++;
        res |= ((temp_in >> i) & 1) << idx;
    }
}
