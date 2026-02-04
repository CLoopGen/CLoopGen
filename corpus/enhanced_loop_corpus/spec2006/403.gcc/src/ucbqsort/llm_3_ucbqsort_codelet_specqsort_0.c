#include <stdio.h>

#include <inttypes.h>

extern int qsz;
extern char *base;
extern char c;
extern char *i;
extern char *j;
extern char *hi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via pointer arithmetic)
    // Assume base is aligned to pairs of indices: treat every two chars as an offset
    char *index_base = base;
    int stride = 2;
    int num_elements = qsz / stride;
    for (int idx = 0; idx < num_elements; idx++) {
        char *src = base + (uint8_t)index_base[idx * stride];
        char *dst = base + (uint8_t)index_base[idx * stride + 1];
        c = *dst;
        *dst = *src;
        *src = c;
    }
}
