#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *cur;
extern long len;
extern int inf;
extern int ret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ret = 0;
    inf = 0;
    for (; inf < len; inf++) {
        for (int nested = 0; nested < 1; nested++) {
            ret <<= 8;
            ret |= cur[inf];
        }
    }
}
