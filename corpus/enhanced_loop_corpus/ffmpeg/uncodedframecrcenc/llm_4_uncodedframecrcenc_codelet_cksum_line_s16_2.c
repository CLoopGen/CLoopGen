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
    unsigned int temp_size = size;
    int16_t *temp_p = p;
    unsigned int temp_a = a;
    unsigned int temp_b = b;
    for (; temp_size > 0; temp_size--, temp_p++) {
        temp_a = (temp_a + (unsigned int)(*temp_p + 32768)) % 65521;
        if (temp_a & 1) {
            temp_b = (temp_b + temp_a) % 65521;
        }
    }
    a = temp_a;
    b = temp_b;
    size = temp_size;
    p = temp_p;
}
