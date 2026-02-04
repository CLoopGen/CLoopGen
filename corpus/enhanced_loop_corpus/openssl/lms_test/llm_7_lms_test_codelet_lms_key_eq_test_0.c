#include <stdio.h>

#include <inttypes.h>

typedef struct evp_pkey_st EVP_PKEY;

extern EVP_PKEY *key[4];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t total = sizeof(key) / sizeof((key)[0]);
    volatile size_t j = total - 1;
    for (i = 0; i < total; i++) {
        key[i] = ((void *)0);
        if (j >= i) // Eliminate loop-carried dependency by making each iteration independent
            key[j - i] = ((void *)0); // Write to symmetric index, no data flow between iterations
    }
}
