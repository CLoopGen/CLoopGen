#include <stdio.h>

#include <inttypes.h>

extern uint8_t *key;
extern size_t len;
extern uint64_t hash;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp_hash = hash;
    for (i = 0; i < len; i++) {
        temp_hash ^= key[i];
        temp_hash *= 1099511628211ULL;
    }
    hash = temp_hash;
}
