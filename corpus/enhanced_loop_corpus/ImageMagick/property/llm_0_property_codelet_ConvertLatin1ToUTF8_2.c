#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char *restrict content;
extern  unsigned char *restrict p;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = content; *p != '\x00'; p++) {
        length += (*p & 128) != 0 ? 2 : 1;
        if ((*p & 64) == 0) {
            unsigned char *q;
            for (q = p + 1; *q != '\x00' && (q - p) <= 10; q++) {
                length += (*q & 32) != 0 ? 1 : 0;
            }
        }
    }
}
