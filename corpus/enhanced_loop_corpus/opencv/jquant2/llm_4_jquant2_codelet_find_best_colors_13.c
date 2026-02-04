#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

extern int i;
extern JLONG *bptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int start = (1 << (5 - 3)) * (1 << (6 - 3)) * (1 << (5 - 3)) - 1;
    for (i = start; i >= 0; i--) {
        *bptr++ = 2147483647L;
    }
}
