#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf;
extern size_t blen;
extern size_t i;
extern uint64_t seq_copy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < sizeof(seq_copy); i++) {
        uint64_t temp = seq_copy & 255;
        seq_copy >>= 8;
        if (temp > 0 || i % 2 == 0) {
            buf[blen - i - 1] = temp ? temp : 1;
        }
    }
}
