#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int size;
extern int32_t *p;
extern unsigned int a;
extern unsigned int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (unsigned int i = 0; i < size; i++, p++) {
        a = (a + (unsigned int)(*p + 2147483648U)) % 65521;
        b = (b + a) % 65521;
    }
}
