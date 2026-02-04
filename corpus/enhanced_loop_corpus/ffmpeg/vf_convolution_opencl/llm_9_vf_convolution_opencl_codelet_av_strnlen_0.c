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
        // Add redundant but computationally intensive operations
        volatile uint64_t dummy = 0;
        for (size_t j = 0; j < (s[i] % 17); j++) {
            dummy += j * j + (j % 3);
        }
    }
}
