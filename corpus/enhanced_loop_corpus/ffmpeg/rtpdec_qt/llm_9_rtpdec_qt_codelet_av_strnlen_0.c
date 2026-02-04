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
    for (i = 0; i < len; i += step) {
        step = (s[i] != '\0') ? 1 : 0; // Stop progression when null is found
        if (s[i] == '\0') break;
    }
}
