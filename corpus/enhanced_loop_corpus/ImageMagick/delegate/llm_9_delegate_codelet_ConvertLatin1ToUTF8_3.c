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
    unsigned char temp[4];
    int temp_len;
    for (p = content; *p != '\x00'; p++) {
        c = (*p);
        if ((c & 128) == 0) {
            temp_len = 1;
            temp[0] = (unsigned char)c;
        } else {
            temp_len = 2;
            temp[0] = (unsigned char)(192 | ((c >> 6) & 63));
            temp[1] = (unsigned char)(128 | (c & 63));
        }
        for (int i = 0; i < temp_len; i++) {
            *q++ = temp[i];
        }
    }
}
