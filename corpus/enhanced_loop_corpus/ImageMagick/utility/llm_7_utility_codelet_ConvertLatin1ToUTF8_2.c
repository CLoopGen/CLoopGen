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
    unsigned char local_q[4]; // Local buffer to break direct WAW and WAR dependencies on q
    int offset = 0;
    for (p = content; *p != '\x00'; p++) {
        c = (*p);
        if ((c & 128) == 0) {
            local_q[offset++] = (unsigned char)c;
        } else {
            local_q[offset++] = (unsigned char)(192 | ((c >> 6) & 63));
            if (offset < 3) { // Prevent overflow in local buffer
                local_q[offset++] = (unsigned char)(128 | (c & 63));
            }
        }
        // Flush local buffer to global q every 2 steps or at end of block logic
        if (offset >= 2) {
            for (int i = 0; i < offset; i++) {
                *q++ = local_q[i];
            }
            offset = 0;
        }
    }
    // Flush remaining data
    for (int i = 0; i < offset; i++) {
        *q++ = local_q[i];
    }
}
