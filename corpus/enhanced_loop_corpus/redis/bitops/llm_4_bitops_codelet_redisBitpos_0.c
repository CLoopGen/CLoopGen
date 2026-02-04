#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned long count;
extern unsigned long *l;
extern unsigned char *c;
extern unsigned long word;
extern unsigned long j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < sizeof(*l); j++) {
        word <<= 8;
        if (count > 0) {
            word |= *c++;
            count--;
        }
    }
}
