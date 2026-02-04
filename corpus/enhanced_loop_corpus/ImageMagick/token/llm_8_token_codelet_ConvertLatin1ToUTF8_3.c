#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char *restrict content;
extern int c;
extern  unsigned char *restrict p;
extern unsigned char *restrict q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = content; *p != '\x00'; p += 2) {
        if (*(p + 1) == '\x00') break;
        c = (*p);
        int c_next = (*(p + 1));
        if ((c & 128) == 0) {
            *q++ = (unsigned char)c;
        } else {
            *q++ = (unsigned char)(192 | ((c >> 6) & 63));
            *q++ = (unsigned char)(128 | (c & 63));
        }
        if ((c_next & 128) == 0) {
            *q++ = (unsigned char)c_next;
        } else {
            *q++ = (unsigned char)(192 | ((c_next >> 6) & 63));
            *q++ = (unsigned char)(128 | (c_next & 63));
        }
    }
    // Handle last odd element if needed
    if (*p != '\x00') {
        c = (*p);
        if ((c & 128) == 0)
            *q++ = (unsigned char)c;
        else {
            *q++ = (unsigned char)(192 | ((c >> 6) & 63));
            *q++ = (unsigned char)(128 | (c & 63));
        }
    }
}
