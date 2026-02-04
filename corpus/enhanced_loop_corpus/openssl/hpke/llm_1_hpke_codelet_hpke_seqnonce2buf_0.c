#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf;
extern size_t blen;
extern size_t i;
extern uint64_t seq_copy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < sizeof(seq_copy); i++) {
        for (size_t inner = 0; inner < 1; inner++) {
            buf[blen - i - 1] = seq_copy & 255;
            seq_copy >>= 8;
        }
    }
}
