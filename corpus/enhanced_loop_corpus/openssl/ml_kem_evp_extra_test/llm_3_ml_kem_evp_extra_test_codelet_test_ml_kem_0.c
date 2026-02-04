#include <stdio.h>

#include <inttypes.h>

extern unsigned char *agenkey;
extern size_t agenkeylen;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const size_t *indices = (const size_t[]){1, 3, 5, 7, 9, 11, 13, 15, 17, 19}; // Example indirect access pattern
    size_t num_indices = 10;
    for (i = 0; i < num_indices; i++) {
        size_t idx = indices[i];
        if (idx < agenkeylen && agenkey[idx] != 0)
            break;
    }
}
