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
    size_t j = i;
    ptrdiff_t offset = 0;
    while ((offset + 2) < (ptrdiff_t)blob_length) {
        unsigned char temp[3] = { blob[offset], blob[offset+1], blob[offset+2] };

        encode[j+0] = Base64[temp[0] >> 2];
        encode[j+1] = Base64[((temp[0] & 3) << 4) | (temp[1] >> 4)];
        encode[j+2] = Base64[((temp[1] & 15) << 2) | (temp[2] >> 6)];
        encode[j+3] = Base64[temp[2] & 63];

        j += 4;
        offset += 3;
    }
    i = j;
}
