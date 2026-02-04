#include <stdio.h>

#include <inttypes.h>

extern  unsigned short *p;
extern unsigned short *q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 3; i < (3 * 3); i++) {
        unsigned short temp1 = *p--;
        unsigned short temp2 = *p--;
        *q++ = temp1 + temp2;
    }
}
