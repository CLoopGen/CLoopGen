#include <stdio.h>

#include <inttypes.h>

extern int left;
extern unsigned int x;
extern unsigned int *s;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (left = 0; left < 1; left++) {
        *s++ = x;
        j = 624;
        for (; --j; ) {
            x *= 69069U;
            *s++ = x & 4294967295U;
        }
    }
}
