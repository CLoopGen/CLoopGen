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
    unsigned char has_data = (count > 0);
    for (j = 0; j < sizeof(*l); j++) {
        word <<= 8;
        if (has_data && j < count) {
            word |= c[j];
        }
    }
}
