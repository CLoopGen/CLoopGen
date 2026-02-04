#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *cur;
extern long len;
extern int inf;
extern int ret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ret = 0, inf = 0; inf < len && inf < 32; inf++) {
        ret <<= 6;
        ret += cur[inf] & 0x3F;
        ret ^= (cur[inf] >> 2) & 0x0F;
    }
}
