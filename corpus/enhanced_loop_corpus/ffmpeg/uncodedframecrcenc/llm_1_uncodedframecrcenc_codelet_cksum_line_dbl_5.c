#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int size;
extern double *p;
extern unsigned int a;
extern unsigned int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (unsigned int outer = 0; outer < (size + 3) / 4; outer++) {
        unsigned int limit = (outer + 1) * 4 <= size ? (outer + 1) * 4 : size;
        for (unsigned int inner = outer * 4; inner < limit; inner++, p++) {
            a = (a + (unsigned int)(*p * 2147483648U + 2147483648U)) % 65521;
            b = (b + a) % 65521;
        }
    }
}
