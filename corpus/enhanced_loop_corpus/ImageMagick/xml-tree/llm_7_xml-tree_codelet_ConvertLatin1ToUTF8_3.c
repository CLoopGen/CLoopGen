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
    unsigned char local_q1, local_q2;
    ptrdiff_t offset = 0;
    for (p = content; *p != '\x00'; p++) {
        c = (*p);
        if ((c & 128) == 0) {
            local_q1 = (unsigned char)c;
            *(q + offset) = local_q1;
            offset += 1;
        } else {
            local_q1 = (unsigned char)(192 | ((c >> 6) & 63));
            local_q2 = (unsigned char)(128 | (c & 63));
            *(q + offset) = local_q1;
            *(q + offset + 1) = local_q2;
            offset += 2;
        }
    }
    q += offset;
}
