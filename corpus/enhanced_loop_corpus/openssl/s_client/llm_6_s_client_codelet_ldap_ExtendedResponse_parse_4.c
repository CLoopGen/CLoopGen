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
    long i;
    for (i = len - 1; i >= 0; i--) {
        ret |= ((int)cur[i]) << (8 * (len - 1 - i));
    }
}
