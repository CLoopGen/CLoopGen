#include <stdio.h>

#include <inttypes.h>

extern unsigned char *pn_bytes;
extern unsigned char mask[5];
extern unsigned char pn_len;
extern unsigned char i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with reverse traversal and stride of 2
    for (i = (pn_len & 1) ? pn_len - 1 : pn_len - 2; i < pn_len && i >= 0; i -= 2)
        pn_bytes[i] ^= mask[i + 1];
}
