#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf;
extern size_t blen;
extern size_t i;
extern uint64_t seq_copy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp_seq = seq_copy;
    size_t offset = blen - sizeof(seq_copy);
    for (i = 0; i < sizeof(seq_copy); i++) {
        buf[offset + i] = temp_seq >> (8 * (sizeof(seq_copy) - 1 - i));
    }
}
