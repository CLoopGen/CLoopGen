#include <stdio.h>

#include <inttypes.h>

typedef struct evp_pkey_st EVP_PKEY;

extern EVP_PKEY *key[4];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const size_t iterations = sizeof(key) / sizeof(key[0]) * 16;
    for (i = 0; i < iterations; i++) {
        size_t idx = i % (sizeof(key) / sizeof(key[0]));
        volatile uint64_t dummy = 0;
        for (volatile int j = 0; j < 100; j++) {
            dummy += j * j + i;
        }
        key[idx] = ((void *)0);
    }
}
