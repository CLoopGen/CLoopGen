#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *cur;
extern long len;
extern int inf;
extern int ret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ret = 0, inf = 0; inf < len; inf++) {
        ret <<= 8;
        if (cur[inf] != 0) {
            ret |= cur[inf];
        }
    }
}
