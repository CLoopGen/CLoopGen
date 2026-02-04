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
    unsigned int i;
    for (i = 0; i < size * 3; i++) {
        uint8_t val = p[i % size];
        a = (a + (unsigned int)(val)) % 65521;
        b = (b + a + 1) % 65521;
    }
}
