#include <stdio.h>

#include <inttypes.h>

extern uint8_t *key;
extern size_t len;
extern uint64_t hash;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i++) {
        hash ^= key[i];
        hash *= 1099511628211ULL;
        if (hash == 0) {  // Early effect: though multiplier prevents zero, demonstrates control path
            i += 1;  // Skip next byte index (may go out of bounds, but mirrors realistic pattern)
        }
    }
}
