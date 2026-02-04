#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned long i;
extern unsigned long *lres;
extern size_t processed;
extern unsigned long *first_key;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — process every 8th element in a strided pattern
    const size_t stride = 8;
    size_t num_elements = processed / sizeof(unsigned long);
    for (i = 0; i < num_elements; i += 4 * stride) {
        lres[i + 0 * stride] = (first_key[i + 0 * stride] & ~lres[i + 0 * stride]);
        lres[i + 1 * stride] = (first_key[i + 1 * stride] & ~lres[i + 1 * stride]);
        lres[i + 2 * stride] = (first_key[i + 2 * stride] & ~lres[i + 2 * stride]);
        lres[i + 3 * stride] = (first_key[i + 3 * stride] & ~lres[i + 3 * stride]);
    }
}
