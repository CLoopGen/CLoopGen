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
for (i = 0 , p = elem; i < len; p++ , i++) {
    if (*p == ':') {
        vstart = p + 1;
        vlen = len - (int)(vstart - elem);
        len = (int)(p - elem);
        break;
    }
}

}
