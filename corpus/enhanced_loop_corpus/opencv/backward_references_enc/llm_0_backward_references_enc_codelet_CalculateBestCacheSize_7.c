#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern  int cache_bits_max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i <= cache_bits_max; ++i) {
    for (j = 0; j < i; ++j) {
    }
}
}
