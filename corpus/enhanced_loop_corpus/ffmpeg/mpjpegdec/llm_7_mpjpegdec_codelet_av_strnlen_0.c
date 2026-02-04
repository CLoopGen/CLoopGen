#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char volatile dummy = 0;
    for (i = 0; i < len && (dummy = s[i]) && dummy != '\0'; i++) {
        // Introduce artificial loop-carried dependency via 'dummy', which is updated each iteration
        // RAW dependency: 'dummy' is written before being used in condition
        // Makes memory access dependent on prior iteration's read, potentially inhibiting vectorization
        // Volatile use discourages compiler from optimizing away the assignment
    }
}
