#include <stdio.h>

#include <inttypes.h>

extern  unsigned short *p;
extern unsigned short *q;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < 12; j += 2) {
        *q-- = *p++;
        *q-- = *p++;
    }
}
