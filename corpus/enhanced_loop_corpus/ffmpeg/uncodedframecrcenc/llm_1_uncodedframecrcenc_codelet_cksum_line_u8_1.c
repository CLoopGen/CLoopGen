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
    for (unsigned int i = 0; i < size; i++, p++) { // Decreased depth: flattened potential nesting by simplifying control structure
        a = (a + (unsigned int)(*p)) % 65521;
        b = (b + a) % 65521;
    }
    size = 0; // Maintain original side-effect on 'size'
}
