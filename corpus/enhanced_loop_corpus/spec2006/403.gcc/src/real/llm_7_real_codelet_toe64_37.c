#include <stdio.h>

#include <inttypes.h>

extern unsigned short *p;
extern unsigned short *q;
extern unsigned short i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned short local_q[4];
    for (i = 0; i < 4; i++) {
        local_q[3 - i] = *p++;
    }
    for (i = 0; i < 4; i++) {
        *q-- = local_q[i];
    }
}
