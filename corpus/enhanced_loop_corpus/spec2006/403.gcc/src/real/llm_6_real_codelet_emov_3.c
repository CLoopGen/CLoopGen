#include <stdio.h>

#include <inttypes.h>

extern  unsigned short *a;
extern unsigned short *b;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned short temp;
    for (i = 0; i < 6; i++) {
        temp = *a++;
        *b++ = temp;
    }
}
