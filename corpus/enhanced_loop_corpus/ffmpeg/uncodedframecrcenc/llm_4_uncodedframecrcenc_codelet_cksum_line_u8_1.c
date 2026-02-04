#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int size;
extern uint8_t *p;
extern unsigned int a;
extern unsigned int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int temp_a;
    for (; size > 0; size--, p++) {
        temp_a = a + (unsigned int)(*p);
        if (temp_a >= 65521) {
            temp_a %= 65521;
        }
        a = temp_a;
        b = (b + a);
        if (b >= 65521) {
            b %= 65521;
        }
    }
}
