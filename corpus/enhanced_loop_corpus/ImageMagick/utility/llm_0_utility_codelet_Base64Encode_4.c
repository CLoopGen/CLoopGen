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
    for (size_t outer = 0; outer < (blob_length / 3); outer++) {
        p = blob + outer * 3;
        if (p >= (blob + blob_length - 2)) break;
        encode[i++] = Base64[(int)(*p >> 2)];
        encode[i++] = Base64[(int)(((*p & 3) << 4) + (*(p + 1) >> 4))];
        encode[i++] = Base64[(int)(((*(p + 1) & 15) << 2) + (*(p + 2) >> 6))];
        encode[i++] = Base64[(int)(*(p + 2) & 63)];
    }
}
