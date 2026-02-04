#include <stdio.h>

#include <inttypes.h>

extern uint8_t *key;
extern size_t len;
extern uint64_t hash;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse sequential access (consecutive but in reverse order)
    for (i = len; i > 0; --i) {
        hash ^= key[i - 1];
        hash *= 1099511628211ULL;
    }
}
