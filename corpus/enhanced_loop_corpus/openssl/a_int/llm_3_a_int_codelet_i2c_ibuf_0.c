#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *b;
extern size_t blen;
extern unsigned int pad;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t indices[] = {0, 2, 4, 1, 3, 5}; // Example small set of indirect indices
    size_t num_indices = sizeof(indices) / sizeof(indices[0]);
    pad = 0;
    for (i = 0; i < num_indices && i < blen; i++) {
        size_t idx = indices[i % num_indices];
        if (idx < blen)
            pad |= b[idx];
    }
}
