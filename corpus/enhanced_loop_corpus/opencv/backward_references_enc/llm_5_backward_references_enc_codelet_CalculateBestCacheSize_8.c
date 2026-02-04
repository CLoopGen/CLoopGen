#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern  int cache_bits_max;
extern int key;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = cache_bits_max; i >= 1; --i, key >>= 1) {
        if (i % 2 == 0) {
            i -= 1;
        }
    }
}
