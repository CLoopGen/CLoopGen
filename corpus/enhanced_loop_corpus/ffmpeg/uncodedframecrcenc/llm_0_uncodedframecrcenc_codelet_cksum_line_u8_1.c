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
    for (; size > 0; size--, p++) {
        for (int inner = 0; inner < 1; inner++) { // Increased depth: introduced a constant-bound inner loop
            a = (a + (unsigned int)(*p)) % 65521;
            b = (b + a) % 65521;
        }
    }
}
