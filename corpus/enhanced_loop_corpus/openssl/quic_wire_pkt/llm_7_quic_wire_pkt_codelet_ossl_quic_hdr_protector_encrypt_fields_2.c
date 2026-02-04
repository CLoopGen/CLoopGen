#include <stdio.h>

#include <inttypes.h>

extern unsigned char *pn_bytes;
extern unsigned char mask[5];
extern unsigned char pn_len;
extern unsigned char i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char prev_index = 0;
    for (i = 0; i < pn_len; ++i) {
        unsigned char idx = (i == 0) ? 1 : prev_index + 1;
        pn_bytes[i] ^= mask[idx % 5];
        prev_index = i + 1;
    }
}
