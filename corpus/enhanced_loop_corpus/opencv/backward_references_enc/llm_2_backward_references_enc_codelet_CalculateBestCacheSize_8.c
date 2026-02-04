#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern  int cache_bits_max;
extern int key;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    extern int i;
    extern int cache_bits_max;
    extern int key;
    volatile int dummy_array[32]; // Simulate memory accesses
    for (i = cache_bits_max; i >= 1; --i, key >>= 1) {
        dummy_array[i % 32] += 1; // Strided access with modulo to stay in bounds
    }
}
