#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2) with bounds checking
    for (i = 0; i < len && (i + 1 < len ? s[i] || s[i+1] : s[i]); i += 2)
        ;
}
