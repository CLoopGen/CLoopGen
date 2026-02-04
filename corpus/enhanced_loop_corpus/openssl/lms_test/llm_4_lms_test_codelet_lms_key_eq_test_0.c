#include <stdio.h>

#include <inttypes.h>

typedef struct evp_pkey_st EVP_PKEY;

extern EVP_PKEY *key[4];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t size = sizeof(key) / sizeof((key)[0]);
    for (i = 0; i < size; i++) {
        if (key[i] != ((void *)0)) {
            key[i] = ((void *)0);
        }
    }
}
