#include <stdio.h>

#include <inttypes.h>

extern unsigned char *pn_bytes;
extern unsigned char mask[5];
extern unsigned char pn_len;
extern unsigned char i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < pn_len; i += 2) {
        if (i + 1 < pn_len) {
            pn_bytes[i] ^= mask[i + 1];
            pn_bytes[i + 1] ^= mask[(i + 2) % 5];
        } else {
            pn_bytes[i] ^= mask[i + 1];
        }
    }
}
