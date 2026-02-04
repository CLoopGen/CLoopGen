#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *wrap_p;
extern int *block_p;
extern unsigned int sub_len;
extern unsigned int sub_count;
extern unsigned int i;
extern unsigned int j;
extern int *p;
extern unsigned int r0;
extern unsigned int r1;
extern unsigned int r2;
extern unsigned int r3;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < sub_len; i++) {
    p = block_p;
    r0 = wrap_p[0];
    r1 = wrap_p[1];
    for (j = 0; j < sub_count / 4; j++) {
        r2 = *p;
        *p = r1 * 3 + (r0 - r2) + 1;
        p += sub_len;
        r3 = *p;
        *p = r2 * 3 - (r1 - r3) - 1;
        p += sub_len;
        r0 = r2;
        r1 = r3;
        if (j + 1 < sub_count / 4) {
            r2 = *p;
            *p = r1 * 3 + (r0 - r2) + 1;
            p += sub_len;
            r3 = *p;
            *p = r2 * 3 - (r1 - r3) - 1;
            p += sub_len;
            r0 = r2;
            r1 = r3;
        }
    }
    *wrap_p++ = r0;
    *wrap_p++ = r1;
    block_p++;
}
}
