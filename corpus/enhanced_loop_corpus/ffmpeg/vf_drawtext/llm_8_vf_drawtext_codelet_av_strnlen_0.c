#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len && s[i] != '\0'; i += 1) {
        // Introduce dummy arithmetic operations to increase computational intensity
        volatile size_t dummy = i * i + 3;
        dummy %= (len > 0 ? len : 1);
    }
}
