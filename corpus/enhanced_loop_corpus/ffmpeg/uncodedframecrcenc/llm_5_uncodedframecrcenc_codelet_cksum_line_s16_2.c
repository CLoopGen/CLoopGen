#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int size;
extern int16_t *p;
extern unsigned int a;
extern unsigned int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; size > 0; size--, p++) {
        unsigned int val = (unsigned int)(*p + 32768);
        a = (a + val) % 65521;
        b = (b + a) % 65521;
        if (val == 0) continue;
    }
}
