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
    unsigned char temp_low, temp_high;
    for (p = content; *p != '\x00'; p++) {
        c = (*p);
        if ((c & 128) == 0) {
            temp_low = (unsigned char)c;
            *q++ = temp_low;
        } else {
            temp_high = (unsigned char)(192 | ((c >> 6) & 63));
            temp_low = (unsigned char)(128 | (c & 63));
            *q++ = temp_high;
            *q++ = temp_low;
        }
    }
}
