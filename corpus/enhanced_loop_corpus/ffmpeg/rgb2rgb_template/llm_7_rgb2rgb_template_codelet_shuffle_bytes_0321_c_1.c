#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
register unsigned int temp = 0;
for (; idx < 15; idx += 4) {
    register unsigned int v = temp ^ idx, g = v & 16711935;
    v &= 4278255360U;
    temp = v;
}
}
