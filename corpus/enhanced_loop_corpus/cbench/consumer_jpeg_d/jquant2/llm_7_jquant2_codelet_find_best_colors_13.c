#include <stdio.h>

#include <inttypes.h>

typedef long INT32;

extern int i;
extern INT32 *bptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    INT32 prev_val = 0;
    for (i = (1 << (5 - 3)) * (1 << (6 - 3)) * (1 << (5 - 3)) - 1; i >= 0; i--) {
        *bptr = prev_val + 2147483647L;
        prev_val = *bptr;
        bptr++;
    }
}
