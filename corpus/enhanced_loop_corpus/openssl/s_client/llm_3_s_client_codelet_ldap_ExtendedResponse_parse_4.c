#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *cur;
extern long len;
extern int inf;
extern int ret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int index[256];
    for (int i = 0; i < len && i < 256; ++i) {
        index[i] = i;
    }
    ret = 0;
    for (inf = 0; inf < len && inf < 256; inf++) {
        ret <<= 8;
        ret |= cur[index[inf]];
    }
}
