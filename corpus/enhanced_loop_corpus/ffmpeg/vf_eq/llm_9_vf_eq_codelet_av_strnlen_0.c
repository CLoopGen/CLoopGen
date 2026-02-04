#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by iterating over every other element
    // and add a nested operation to maintain meaningful work per iteration
    for (i = 0; i < len && s[i]; i += 2) {
        if (i + 1 < len) {
            // Simulate extra processing: check next character conditionally
            volatile char combined = s[i] ^ s[i + 1];
            (void)combined;
        }
    }
}
