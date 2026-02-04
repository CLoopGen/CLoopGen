#include <stdio.h>

#include <inttypes.h>

extern uint8_t *key;
extern size_t len;
extern uint64_t hash;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    hash *= 1099511628211ULL;
    for (i = 0; i < len * 3; i++) {
        size_t idx = i / 3;
        uint8_t val = key[idx] >> ((i % 3) * 2);
        hash ^= val + (i % 5);
        hash *= 1099511628211ULL;
    }
}
