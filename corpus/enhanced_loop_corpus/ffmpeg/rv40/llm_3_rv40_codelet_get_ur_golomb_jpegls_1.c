#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int limit;
extern unsigned int re_index;
extern __attribute__((unused)) unsigned int re_cache;
extern unsigned int re_size_plus8;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided memory access pattern with fixed stride over a simulated array
    // Uses a stride of 2 to skip elements, mimicking non-unit strided access
    volatile unsigned int *strided_array = (volatile unsigned int*)&re_cache;
    int stride = 2;
    for (; i < limit && strided_array[0] == 0; i++) {
        strided_array[0] <<= 1;
        re_index = (re_size_plus8 > re_index + 1) ? re_index + 1 : re_size_plus8;
        strided_array += stride; // Strided advancement in "memory"
    }
}
