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
        // Add dummy arithmetic to increase computational intensity
        step = 1 + ((i & 1) ^ (s[i] % 2)); // Variable step based on index and char value
        if (step == 0) step = 1;
    }
}
