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
    volatile int dummy_array[64];
    int indices[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50}; // Predefined index set
    int idx_size = sizeof(indices) / sizeof(indices[0]);
    for (i = cache_bits_max; i >= 1; --i, key >>= 1) {
        if ((i % 5) == 0 && (i/5 - 1) < idx_size) {
            dummy_array[indices[i/5 - 1]] += key; // Indirect access via index array
        }
    }
}
