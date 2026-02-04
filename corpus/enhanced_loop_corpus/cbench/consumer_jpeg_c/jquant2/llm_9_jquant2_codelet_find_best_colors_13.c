#include <stdio.h>

#include <inttypes.h>

typedef long INT32;

extern int i;
extern INT32 *bptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = (1 << (7 - 4)) * (1 << (8 - 5)) + 5;
    for (i = 0; i < limit; i += 2) {
        *bptr++ = 2147483647L;
        if (i + 1 < limit) {
            *bptr++ = 2147483647L;
        }
    }
}
