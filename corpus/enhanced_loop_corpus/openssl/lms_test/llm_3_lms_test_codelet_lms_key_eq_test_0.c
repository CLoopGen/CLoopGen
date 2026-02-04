#include <stdio.h>

#include <inttypes.h>

typedef struct evp_pkey_st EVP_PKEY;

extern EVP_PKEY *key[4];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array
    size_t indices[] = {0, 1, 2, 3}; // indirect addressing
    size_t size = sizeof(indices) / sizeof(indices[0]);
    size_t j;
    for (j = 0; j < size; j++) {
        key[indices[j]] = ((void *)0);
    }
}
