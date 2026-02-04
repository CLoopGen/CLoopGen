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
        for (int i = 0; i < 2 && *inner_p != '\x00'; i++, inner_p++) {
            inner_count += (*inner_p & 128) != 0 ? 2 : 1;
        }
        length += inner_count;
        p = inner_p;
    }
}
