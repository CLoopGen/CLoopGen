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
    for (p = content; *p != '\x00'; p++) {
        c = (*p);
        *q++ = (unsigned char)((c & 128) == 0 ? c : (192 | ((c >> 6) & 63)));
        if ((c & 128) != 0)
            *q++ = (unsigned char)(128 | (c & 63));
    }
}
