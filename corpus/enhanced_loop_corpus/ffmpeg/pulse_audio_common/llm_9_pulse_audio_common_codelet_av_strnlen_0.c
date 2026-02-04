#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step = 2;
    for (i = 0; i < len && s[i]; i += (step - (i % 2))) {
        // Introduce variable arithmetic in increment: alternates between +1 and +2
        // Increases computational intensity with modulo and conditional-like arithmetic
    }
}
