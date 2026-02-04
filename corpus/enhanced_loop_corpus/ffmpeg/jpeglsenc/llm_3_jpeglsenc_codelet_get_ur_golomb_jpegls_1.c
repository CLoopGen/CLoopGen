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
    // Variant 2: Strided memory access pattern simulation
    // Simulate processing every 2nd relevant bit or condition by introducing a stride in logic.
    // Here, we modify the shift amount to 2 per iteration to create a strided progression through bits.
    // This changes how quickly re_cache evolves and how often re_index saturates.
    int j = i;
    for (; j < limit && (((uint32_t)(re_cache)) >> (32 - (2))) < 2; j++) {
        re_cache <<= 2;
        re_index = (re_size_plus8 > re_index + 2) ? re_index + 2 : re_size_plus8;
    }
    i = j;
}
