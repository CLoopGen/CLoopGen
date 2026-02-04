#include <stdint.h>
#include <stdlib.h>
#include <string.h>

unsigned char *pn_bytes;
unsigned char mask[5] = {0x01, 0x02, 0x03, 0x04, 0x05};
unsigned char pn_len;
unsigned char i;

void init_vars() {
    pn_len = 255; // Ensures i+1 access to mask[i+1] stays within bounds (i < 255 => i+1 <= 255, but mask size is 5)
    
    // Adjust pn_len so that i+1 does not exceed mask array bounds
    pn_len = 4; // Now i goes from 0 to 3, so mask[i+1] accesses mask[1] to mask[4] -> valid

    pn_bytes = (unsigned char*)malloc(4);
    if (!pn_bytes) {
        pn_len = 0;
        return;
    }
    memset(pn_bytes, 0xAA, 4); // Initialize with sample data
}