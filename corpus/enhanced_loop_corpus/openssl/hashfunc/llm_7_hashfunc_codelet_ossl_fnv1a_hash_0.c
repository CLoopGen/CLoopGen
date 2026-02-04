#include <stdio.h>

#include <inttypes.h>

extern uint8_t *key;
extern size_t len;
extern uint64_t hash;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t local_hash = 14695981039346656037ULL;
    for (i = 0; i < len; i++) {
        local_hash ^= (key[i] ^ (local_hash >> 8));
        local_hash *= 1099511628211ULL;
    }
    hash = local_hash ^ hash;
}
