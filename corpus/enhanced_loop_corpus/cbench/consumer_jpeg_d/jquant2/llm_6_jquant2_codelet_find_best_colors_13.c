#include <stdio.h>

#include <inttypes.h>

typedef long INT32;

extern int i;
extern INT32 *bptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    INT32 temp = 2147483647L;
    for (i = (1 << (5 - 3)) * (1 << (6 - 3)) * (1 << (5 - 3)) - 1; i >= 0; i--) {
        *bptr = temp;
        bptr++;
    }
}
