#include <stdio.h>

#include <inttypes.h>

extern unsigned char *pn_bytes;
extern unsigned char mask[5];
extern unsigned char pn_len;
extern unsigned char i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access using pointer arithmetic and local stride simulation
    unsigned char *byte_ptr = pn_bytes;
    unsigned char *mask_base = mask + 1;
    for (i = 0; i < pn_len; ++i) {
        *(byte_ptr++) ^= *(mask_base++);
    }
}
