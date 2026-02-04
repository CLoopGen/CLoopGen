#include <stdio.h>

#include <inttypes.h>

extern unsigned char *pn_bytes;
extern unsigned char mask[5];
extern unsigned char pn_len;
extern unsigned char i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < pn_len - 1; ++i) {
        pn_bytes[i] ^= mask[i + 1];
        pn_bytes[i + 1] ^= pn_bytes[i];
    }
    if (pn_len > 0)
        pn_bytes[pn_len - 1] ^= mask[pn_len]; 
    // Introduces a loop-carried RAW dependency: each iteration depends on the previous pn_bytes[i]
    // Alters data flow by making mask application propagate through pn_bytes array elements
    // Ensures semantic validity by handling last element separately to avoid out-of-bounds access
}
