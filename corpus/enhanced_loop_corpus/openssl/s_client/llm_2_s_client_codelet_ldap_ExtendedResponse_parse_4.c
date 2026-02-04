#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *cur;
extern long len;
extern int inf;
extern int ret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ret = 0, inf = 0; inf < len; inf += 2) {
        ret <<= 8;
        if (inf + 1 < len) {
            ret |= cur[inf + 1];
        } else {
            ret |= cur[inf];
        }
    }
}
