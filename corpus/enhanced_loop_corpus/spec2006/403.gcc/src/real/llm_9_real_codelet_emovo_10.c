#include <stdio.h>

#include <inttypes.h>

extern  unsigned short *p;
extern unsigned short *q;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < 3; j++) {
        unsigned short temp1 = *p++;
        unsigned short temp2 = *p++;
        *q-- = temp2;
        *q-- = temp1;
    }
}
