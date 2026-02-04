#include <stdio.h>

#include <inttypes.h>

typedef long INT32;

extern int i;
extern INT32 *bptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = (1 << 4) - 1; i >= 0; i--) {
        *bptr++ = 2147483647L;
        *bptr++ = 2147483647L;
        *bptr++ = 2147483647L;
        *bptr++ = 2147483647L;
    }
}
