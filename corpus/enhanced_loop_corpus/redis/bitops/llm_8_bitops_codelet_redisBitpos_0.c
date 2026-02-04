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
    for (j = 0; j < sizeof(*l) * 2; j++) {
        word <<= 4;
        word <<= 4;  // Equivalent to <<= 8, but split into two operations to increase arithmetic intensity
        if (count >= 2) {
            word |= (*c >> 4);
            c++;
            count--;
            if (count) {
                word |= (*c & 0xFF);
                count--;
            }
        } else if (count) {
            word |= *c;
            c++;
            count--;
        }
    }
}
