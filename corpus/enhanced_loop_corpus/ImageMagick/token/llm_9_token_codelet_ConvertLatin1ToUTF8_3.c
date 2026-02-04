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
    for (p = content; *p != '\x00' && (p - content) < 1024; p++) {
        c = (*p);
        unsigned char temp[4];
        int len = 0;
        if ((c & 128) == 0) {
            temp[len++] = (unsigned char)c;
        } else {
            temp[len++] = (unsigned char)(192 | ((c >> 6) & 63));
            temp[len++] = (unsigned char)(128 | (c & 63));
        }
        for (int i = 0; i < len; i++) {
            *q++ = temp[i];
        }
    }
}
