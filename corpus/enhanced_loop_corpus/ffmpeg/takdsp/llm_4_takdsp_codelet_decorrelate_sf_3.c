#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *p1;
extern int32_t *p2;
extern int length;
extern int dshift;
extern int dfactor;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < length; i += 2) {
    uint32_t a1 = p1[i];
    int32_t b1 = p2[i];
    b1 = (unsigned int)((int)(dfactor * (unsigned int)(b1 >> dshift) + 128) >> 8) << dshift;
    p1[i] = b1 - a1;

    if (i + 1 < length) {
        uint32_t a2 = p1[i + 1];
        int32_t b2 = p2[i + 1];
        b2 = (unsigned int)((int)(dfactor * (unsigned int)(b2 >> dshift) + 128) >> 8) << dshift;
        p1[i + 1] = b2 - a2;
    }
}
}
