#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char *restrict content;
extern  unsigned char *restrict p;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = content; *p != '\x00'; ) {
        unsigned char *inner_p = p;
        size_t inner_count = 0;
        for (; inner_p != NULL && *inner_p != '\x00' && inner_count < 2; inner_count++) {
            length += (*inner_p & 128) != 0 ? 2 : 1;
            if (*inner_p == '\x00') break;
            inner_p++;
        }
        p = (inner_p == p) ? inner_p + 1 : inner_p;
    }
}
