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
    // Variant 2: Strided memory access pattern with indirect indexing
    // Simulate irregular progression by advancing index in variable strides based on control variables
    for (; i < limit && re_cache != 0; i++) {
        re_cache >>= 1;
        re_index = (re_index + 3) % (re_size_plus8 + 1);  // Stride of 3 with modulo to bound within range
    }
}
