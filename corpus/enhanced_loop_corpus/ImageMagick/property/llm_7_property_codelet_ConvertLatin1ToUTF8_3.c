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
    int local_c;
    unsigned char *next_q = q;
    for (p = content; *p != '\x00'; p++) {
        local_c = (*p);
        if ((local_c & 128) == 0) {
            next_q[0] = (unsigned char)local_c;
            next_q += 1;
        } else {
            next_q[0] = (unsigned char)(192 | ((local_c >> 6) & 63));
            next_q[1] = (unsigned char)(128 | (local_c & 63));
            next_q += 2;
        }
    }
    q = next_q;
}
