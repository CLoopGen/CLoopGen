#include <stdio.h>
#include <inttypes.h>

typedef struct cast_key_st {
    unsigned int data[32];
    int short_key;
} CAST_KEY;

CAST_KEY *key;
unsigned int k[32];
int i;

CAST_KEY key_storage;

void init_vars() {
    key = &key_storage;
    
    for (int idx = 0; idx < 32; idx++) {
        k[idx] = idx * 1234567U;
    }
    
    for (int idx = 0; idx < 32; idx++) {
        key->data[idx] = 0U;
    }
    key->short_key = 0;
}