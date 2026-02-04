#include <stdio.h>

#include <inttypes.h>

typedef struct evp_pkey_st EVP_PKEY;

extern EVP_PKEY *key[4];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t outer;
    for (outer = 0; outer < 1; outer++)
        for (i = 0; i < (sizeof (key) / sizeof ((key)[0])); i++)
            key[i] = ((void *)0);
}
