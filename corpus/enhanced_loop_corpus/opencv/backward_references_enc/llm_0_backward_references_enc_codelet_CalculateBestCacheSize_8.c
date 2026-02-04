#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern  int cache_bits_max;
extern int key;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < cache_bits_max; ++j) {
        for (i = cache_bits_max; i >= 1; --i) {
            key >>= 1;
        }
    }
}
