#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf;
extern size_t blen;
extern size_t i;
extern uint64_t seq_copy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t indices[sizeof(seq_copy)];
    size_t j;
    for (j = 0; j < sizeof(seq_copy); j++) {
        indices[j] = blen - j - 1;
    }
    for (j = 0; j < sizeof(seq_copy); j++) {
        buf[indices[j]] = seq_copy & 255;
        seq_copy >>= 8;
    }
}
