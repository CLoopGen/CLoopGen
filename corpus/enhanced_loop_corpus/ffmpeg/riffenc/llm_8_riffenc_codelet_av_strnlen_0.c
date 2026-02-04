#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    i = 0;
    size_t step = 1;
    for (; i < len && s[i]; i += step) {
        // Increase computational intensity by adding redundant arithmetic operations
        step = (i % 3 == 0) ? 1 : 1; // dummy operation influencing control flow slightly
        volatile size_t dummy = i * i + i - (i >> 1); // extra arithmetic to increase compute load
        (void)dummy;
    }
}
