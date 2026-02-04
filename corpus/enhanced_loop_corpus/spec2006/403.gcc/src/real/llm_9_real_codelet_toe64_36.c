#include <stdio.h>

#include <inttypes.h>

extern unsigned short *p;
extern unsigned short *q;
extern unsigned short i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 2; i++) {
        unsigned short temp1 = *p++;
        unsigned short temp2 = *p++;
        *q++ = temp1 + 1;
        *q++ = temp2 + 1;
        *q++ = temp1 + temp2;
        *q++ = temp1 ^ temp2;
    }
}
