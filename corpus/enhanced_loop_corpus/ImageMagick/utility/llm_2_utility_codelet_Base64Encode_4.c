#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char Base64[];
extern  unsigned char *blob;
extern  size_t blob_length;
extern char *encode;
extern  unsigned char *p;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access using array indexing instead of pointer arithmetic
    size_t num_blocks = (blob_length - 2) / 3;
    for (i = 0; i < num_blocks * 4; ) {
        size_t offset = i / 4 * 3;
        encode[i++] = Base64[(int)(blob[offset] >> 2)];
        encode[i++] = Base64[(int)(((blob[offset] & 3) << 4) + (blob[offset + 1] >> 4))];
        encode[i++] = Base64[(int)(((blob[offset + 1] & 15) << 2) + (blob[offset + 2] >> 6))];
        encode[i++] = Base64[(int)(blob[offset + 2] & 63)];
    }
}
