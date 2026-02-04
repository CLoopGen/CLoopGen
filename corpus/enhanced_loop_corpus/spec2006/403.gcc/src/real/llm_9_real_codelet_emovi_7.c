#include <stdio.h>

#include <inttypes.h>

extern  unsigned short *p;
extern unsigned short *q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 3; i++) {
        unsigned short temp1 = *(p - 0);
        unsigned short temp2 = *(p - 1);
        *q++ = temp2;
        *q++ = temp1;
        p -= 2;
    }
}
