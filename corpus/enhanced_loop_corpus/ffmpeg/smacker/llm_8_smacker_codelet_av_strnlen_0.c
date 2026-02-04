#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; i < len && s[i]; i++) {
        for (j = 0; j < 3; j++) {
            // Simulate extra computation without changing logic
            volatile uint64_t dummy = (uint64_t)i * j + 17;
        }
    }
}
