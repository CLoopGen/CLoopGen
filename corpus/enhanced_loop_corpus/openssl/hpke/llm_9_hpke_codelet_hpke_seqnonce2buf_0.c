#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf;
extern size_t blen;
extern size_t i;
extern uint64_t seq_copy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t unroll_factor = 4;
    size_t remainder = sizeof(seq_copy) % unroll_factor;
    size_t limit = sizeof(seq_copy) - remainder;

    for (i = 0; i < limit; i += unroll_factor) {
        buf[blen - i - 1] = seq_copy & 255; seq_copy >>= 8;
        buf[blen - i - 2] = seq_copy & 255; seq_copy >>= 8;
        buf[blen - i - 3] = seq_copy & 255; seq_copy >>= 8;
        buf[blen - i - 4] = seq_copy & 255; seq_copy >>= 8;
    }

    for (; i < sizeof(seq_copy); i++) {
        buf[blen - i - 1] = seq_copy & 255;
        seq_copy >>= 8;
    }
}
