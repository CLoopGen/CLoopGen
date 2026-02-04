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
    for (unsigned int outer = 0; outer < size; outer++) {
        for (unsigned int inner = 0; inner < 1; inner++) {
            a = (a + (unsigned int)(*(p + outer) + 2147483648U)) % 65521;
            b = (b + a) % 65521;
        }
    }
    p += size;
}
