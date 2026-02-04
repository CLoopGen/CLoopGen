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
    unsigned char temp;
    for (p = content; *p != '\x00'; p++) {
        c = (*p);
        temp = (unsigned char)c;
        if ((temp & 128) == 0) {
            *q = temp;
            q++;
        } else {
            *q = (unsigned char)(192 | ((temp >> 6) & 63));
            q++;
            *q = (unsigned char)(128 | (temp & 63));
            q++;
        }
    }
}
