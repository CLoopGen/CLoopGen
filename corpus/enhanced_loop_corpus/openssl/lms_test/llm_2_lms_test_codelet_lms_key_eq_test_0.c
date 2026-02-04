#include <stdio.h>

#include <inttypes.h>

typedef struct evp_pkey_st EVP_PKEY;

extern EVP_PKEY *key[4];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2, unrolled by 2)
    size_t size = sizeof(key) / sizeof(key[0]);
    size_t j;
    for (j = 0; j < size; j += 2) {
        key[j] = ((void *)0);
        if (j + 1 < size)
            key[j + 1] = ((void *)0);
    }
}
