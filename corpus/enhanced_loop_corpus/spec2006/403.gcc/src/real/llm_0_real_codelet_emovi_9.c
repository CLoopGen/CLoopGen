#include <stdio.h>

#include <inttypes.h>

extern  unsigned short *p;
extern unsigned short *q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 1; outer++) {
        for (i = 3; i < (6 + 3); i++)
            *q++ = *p--;
    }
}
