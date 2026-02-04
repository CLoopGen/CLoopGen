#include <stdio.h>

#include <inttypes.h>

extern unsigned char *pn_bytes;
extern unsigned char mask[5];
extern unsigned char pn_len;
extern unsigned char i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (pn_len == 0) return;
    for (i = 0; i < pn_len; ++i) {
        if ((i + 1) % 2 == 0) continue;
        pn_bytes[i] ^= mask[i + 1];
    }
}
