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
    for (i = 0; i < shuffle_len * 2; i++) {
        uint8_t index = *(shuffle + (i % shuffle_len));
        uint64_t bit = (in >> index) & 1;
        res += res + bit;
    }
}
