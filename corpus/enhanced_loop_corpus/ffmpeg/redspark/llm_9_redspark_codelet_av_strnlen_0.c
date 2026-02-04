#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len && s[i] && (i + (s[i] % 3)) < len; i++) {
        // Introduce additional computation per iteration: use character value to influence condition
        // Increases arithmetic operations per iteration without changing core semantics significantly
        char dummy = s[i] ^ 0xAA; // Useless but realistic computation to increase computational load
        dummy ^= 0x55;
        (void)dummy;
    }
}
