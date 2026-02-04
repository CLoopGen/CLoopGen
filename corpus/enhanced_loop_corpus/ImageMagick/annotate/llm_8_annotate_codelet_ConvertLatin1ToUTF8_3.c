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
        if (*(p+1) == '\x00') break;
        c = (*p);
        int c2 = (*(p+1));
        if ((c & 128) == 0)
            *q++ = (unsigned char)c;
        else {
            *q++ = (unsigned char)(192 | ((c >> 6) & 63));
            *q++ = (unsigned char)(128 | (c & 63));
        }
        if ((c2 & 128) == 0)
            *q++ = (unsigned char)c2;
        else {
            *q++ = (unsigned char)(192 | ((c2 >> 6) & 63));
            *q++ = (unsigned char)(128 | (c2 & 63));
        }
    }
    if (*p != '\x00' && p != NULL) {
        c = (*p);
        if ((c & 128) == 0)
            *q++ = (unsigned char)c;
        else {
            *q++ = (unsigned char)(192 | ((c >> 6) & 63));
            *q++ = (unsigned char)(128 | (c & 63));
        }
    }
}
