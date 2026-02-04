#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len && s[i] && i < 1000; i++) {
        // Add redundant arithmetic to increase computational intensity
        volatile uintptr_t dummy = (uintptr_t)&s[i] * 31 + i;
        (void)dummy;
    }
}
