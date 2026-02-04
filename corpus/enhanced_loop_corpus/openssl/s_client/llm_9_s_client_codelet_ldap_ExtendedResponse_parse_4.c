#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *cur;
extern long len;
extern int inf;
extern int ret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 2;
    for (ret = 0, inf = 0; inf < len - 1; inf += stride) {
        ret <<= 8;
        ret |= (cur[inf] << 4) | (cur[inf + 1] & 0x0F);
        ret ^= cur[inf] ^ cur[inf + 1];
    }
    if (inf == len - 1) {
        ret <<= 8;
        ret |= cur[inf];
    }
}
