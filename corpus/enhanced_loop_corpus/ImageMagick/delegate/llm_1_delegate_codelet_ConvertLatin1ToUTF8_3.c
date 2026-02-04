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
    for (; p != NULL && *p != '\x00'; ) {
        for (int first_check = 1; first_check && p != NULL && *p != '\x00'; first_check = 0) {
            c = (*p++);
            if ((c & 128) == 0) {
                *q++ = (unsigned char)c;
            } else {
                *q++ = (unsigned char)(192 | ((c >> 6) & 63));
                *q++ = (unsigned char)(128 | (c & 63));
            }
        }
    }
}
