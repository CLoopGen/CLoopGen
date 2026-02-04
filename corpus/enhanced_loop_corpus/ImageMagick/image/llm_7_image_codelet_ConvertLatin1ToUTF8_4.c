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
    unsigned char *local_q = q;
    for (p = content; *p != '\x00'; p++) {
        c = *p;
        if ((c & 128) == 0) {
            local_q[0] = (unsigned char)c;
            local_q++;
        } else {
            local_q[0] = (unsigned char)(192 | ((c >> 6) & 63));
            local_q[1] = (unsigned char)(128 | (c & 63));
            local_q += 2;
        }
    }
    q = local_q; // Eliminate write-after-write (WAW) on 'q' by using a local accumulator and single store at end
}
