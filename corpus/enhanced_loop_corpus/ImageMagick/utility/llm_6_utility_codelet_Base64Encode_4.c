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
    unsigned char *q = blob;
    size_t j = i;
    for (; q < (blob + blob_length - 2); q += 3) {
        unsigned char val1 = q[0];
        unsigned char val2 = q[1];
        unsigned char val3 = q[2];

        encode[j++] = Base64[val1 >> 2];
        encode[j++] = Base64[((val1 & 3) << 4) | (val2 >> 4)];
        encode[j++] = Base64[((val2 & 15) << 2) | (val3 >> 6)];
        encode[j++] = Base64[val3 & 63];
    }
    i = j;
}
