#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern  int cache_bits_max;
extern int key;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_key = key;
    int local_i = cache_bits_max;
    for (i = cache_bits_max; i >= 1; --i) {
        local_key >>= 1;
        local_i--;
    }
    key = local_key;
    i = local_i;
}
