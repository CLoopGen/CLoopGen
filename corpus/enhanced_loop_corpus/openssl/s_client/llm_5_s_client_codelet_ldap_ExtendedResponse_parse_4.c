#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *cur;
extern long len;
extern int inf;
extern int ret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ret = 0, inf = 0; inf < len && ret <= 0xFFFFFF; inf++) {
        ret <<= 8;
        ret |= cur[inf];
        if (ret == -1) {
            break;
        }
    }
}
