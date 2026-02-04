#include <stdio.h>

#include <inttypes.h>

extern  char *elem;
extern int len;
extern int i;
extern int vlen;
extern  char *p;
extern  char *vstart;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Unroll the loop by a factor of 2 to reduce trip count and increase operations per iteration
    int limit = len - (len % 2);
    for (i = 0, p = elem; i < limit; i += 2, p += 2) {
        if (*p == ':') {
            vstart = p;
            vlen = len - (int)(vstart - elem);
            len = (int)(p - elem);
            break;
        }
        if (*(p + 1) == ':') {
            vstart = p + 1;
            vlen = len - (int)(vstart - elem);
            len = (int)(p + 1 - elem);
            break;
        }
    }
    // Handle remaining element if any
    if (i == len - 1 && *p == ':') {
        vstart = p;
        vlen = len - (int)(vstart - elem);
        len = (int)(p - elem);
    }
}
