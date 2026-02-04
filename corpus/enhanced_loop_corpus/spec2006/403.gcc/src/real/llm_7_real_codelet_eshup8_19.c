#include <stdio.h>

#include <inttypes.h>

extern unsigned short *x;
extern int i;
extern unsigned short newbyt;
extern unsigned short oldbyt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned short *local_x = x;
    unsigned short local_oldbyt = oldbyt;
    unsigned short local_newbyt;

    for (i = 2; i < (6 + 3); i++) {
        local_newbyt = *local_x >> 8;
        *local_x <<= 8;
        *local_x |= local_oldbyt;
        local_oldbyt = local_newbyt;
        local_x--;
    }

    x = local_x;
    oldbyt = local_oldbyt;
}
