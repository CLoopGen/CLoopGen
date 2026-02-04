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
    for (unsigned int outer = size; outer > 0; outer--) {
        for (unsigned int inner = 1; inner > 0; inner--, p++) {
            a = (a + (unsigned int)(*p + 32768)) % 65521;
            b = (b + a) % 65521;
        }
    }
}
