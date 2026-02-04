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
    unsigned char temp;
    for (; inf < len; inf++) {
        temp = cur[inf];
        ret = (ret << 8) | temp;
    }
}
