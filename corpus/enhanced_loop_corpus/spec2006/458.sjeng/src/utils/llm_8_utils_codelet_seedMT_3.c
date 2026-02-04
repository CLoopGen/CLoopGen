#include <stdio.h>

#include <inttypes.h>

extern int left;
extern unsigned int x;
extern unsigned int *s;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (left = 0, *s++ = x, j = (312); --j; *s++ = (x *= 69069U) + (x ^= 27313U), x &= 4294967295U)
        ;
}
