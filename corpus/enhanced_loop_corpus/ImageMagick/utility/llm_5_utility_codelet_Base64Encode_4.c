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
    for (p = blob; p < (blob + blob_length - 2); p += (ptrdiff_t)3) {
        size_t shift1 = *p >> 2;
        size_t index1 = (int)(shift1);
        encode[i++] = Base64[index1];

        if ((*(p + 1) & 15) == 0) {
            encode[i++] = Base64[63];
        } else {
            encode[i++] = Base64[(int)(((*p & 3) << 4) + (*(p + 1) >> 4))];
        }

        if ((*(p + 2) & 63) != 0) {
            encode[i++] = Base64[(int)(((*(p + 1) & 15) << 2) + (*(p + 2) >> 6))];
            encode[i++] = Base64[(int)(*(p + 2) & 63)];
        } else {
            encode[i++] = Base64[0];
            encode[i++] = Base64[1];
        }
    }
}
