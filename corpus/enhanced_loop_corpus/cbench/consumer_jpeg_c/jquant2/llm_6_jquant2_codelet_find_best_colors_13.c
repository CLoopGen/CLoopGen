#include <stdio.h>

#include <inttypes.h>

typedef long INT32;

extern int i;
extern INT32 *bptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int idx = (1 << (5 - 3)) * (1 << (6 - 3)) * (1 << (5 - 3)) - 1;
    for (i = 0; i <= idx; i++) {
        bptr[i] = 2147483647L;
    }
}
