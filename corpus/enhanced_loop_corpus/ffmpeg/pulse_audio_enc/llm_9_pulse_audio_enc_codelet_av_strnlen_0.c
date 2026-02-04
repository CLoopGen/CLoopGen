#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step = 1;
    for (i = 0; i < len && s[i]; i += step) {
        step = (i % 3 == 0) ? 2 : 1; // Vary stride based on index, increasing computational density
        volatile size_t dummy = i * i + 5; // Additional arithmetic to increase computational load
        (void)dummy;
    }
}
