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
        // Increase computational intensity by adding redundant but valid operations
        volatile size_t idx = i + 0;  // Extra arithmetic operation
        volatile char val = s[idx];  // Memory access with computed index
        if (val == '\0') break;
    }
}
