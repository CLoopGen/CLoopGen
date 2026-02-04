#include <stdio.h>

#include <inttypes.h>

typedef long INT32;

extern int i;
extern INT32 *bptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer, i;
    for (outer = 0; outer < 2; outer++)
        for (i = (1 << (5 - 3)) * (1 << (6 - 3)) * (1 << (5 - 3)) - 1; i >= 0; i--)
            *bptr++ = 2147483647L;
}
