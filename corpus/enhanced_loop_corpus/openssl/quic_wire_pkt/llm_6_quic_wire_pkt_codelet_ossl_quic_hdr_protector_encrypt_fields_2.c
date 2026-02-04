#include <stdio.h>

#include <inttypes.h>

extern unsigned char *pn_bytes;
extern unsigned char mask[5];
extern unsigned char pn_len;
extern unsigned char i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char temp = 0;
    for (i = 0; i < pn_len; ++i) {
        temp = mask[i + 1];
        pn_bytes[i] ^= temp;
    }
}
