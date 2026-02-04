#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern  int cache_bits_max;
extern int key;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = cache_bits_max * 2; i >= 1; --i, key >>= 1, key += (key & 1) ? 3 : 0) {
        key ^= i;
        key += (i % 3) ? (key >> 2) : (key << 1);
    }
}
