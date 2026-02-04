#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

extern int i;
extern JLONG *bptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JLONG temp = 2147483647L;
    for (i = (1 << (5 - 3)) * (1 << (6 - 3)) * (1 << (5 - 3)) - 1; i >= 0; i--) {
        *bptr = temp;
        bptr++;
    }
}
