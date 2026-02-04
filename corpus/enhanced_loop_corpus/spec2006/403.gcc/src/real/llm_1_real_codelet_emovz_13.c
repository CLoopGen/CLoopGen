#include <stdio.h>

#include <inttypes.h>

extern  unsigned short *a;
extern unsigned short *b;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < ((6 + 3) - 1) * 2; i++) {
        if (i < (6 + 3) - 1)
            *b++ = *a++;
        else
            break;
    }
}
