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
    p = elem;
    i = 0;

    for (; i < len; ) {
        char val = *(p + i);
        if (val == ':') {
            vstart = p + i + 1;
            vlen = len - i - 1;
            len = i;
            break;
        }
        i++;
    }
}
