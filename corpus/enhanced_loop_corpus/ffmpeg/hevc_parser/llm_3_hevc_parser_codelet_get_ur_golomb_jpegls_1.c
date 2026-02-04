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
    // Variant 2: Strided memory access pattern with fixed stride > 1
    // Access elements in a non-sequential, strided manner from a preallocated array
    // This changes access locality and simulates irregular memory behavior
    
    const int stride = 3;
    uint32_t* buffer = (uint32_t*)calloc(re_size_plus8, sizeof(uint32_t));
    if (!buffer) return;

    for (; i < limit && (((uint32_t)(re_cache)) >> 31) == 0; i++) {
        re_cache <<= 1;
        // Strided access: jump by 'stride', wrap-around if needed
        size_t effective_index = (re_index * stride) % re_size_plus8;
        re_cache |= (buffer[effective_index] & 1); // Inject data bit into LSB
        re_index++;
        if (re_index >= re_size_plus8) re_index = re_size_plus8;
    }

    free(buffer);
}
