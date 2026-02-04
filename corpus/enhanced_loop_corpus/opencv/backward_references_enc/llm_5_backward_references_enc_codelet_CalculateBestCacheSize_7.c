#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern  int cache_bits_max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= cache_bits_max && i < 1000; ++i) {
        if (i == 500) {
            i += 100;
        }
    }
}
