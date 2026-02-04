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
        for (unsigned long shift = 0; shift < 8; shift += 8) {
            word <<= 8;
        }
        if (count) {
            word |= *c;
            c++;
            count--;
        }
    }
}
