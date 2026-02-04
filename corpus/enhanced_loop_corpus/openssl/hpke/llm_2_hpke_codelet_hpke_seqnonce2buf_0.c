#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf;
extern size_t blen;
extern size_t i;
extern uint64_t seq_copy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    uint64_t temp = seq_copy;
    for (j = 0; j < sizeof(seq_copy); j++) {
        buf[blen - sizeof(seq_copy) + j] = temp & 255;
        temp >>= 8;
    }
}
