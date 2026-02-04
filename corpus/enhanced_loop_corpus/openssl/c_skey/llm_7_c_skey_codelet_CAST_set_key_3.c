#include <stdio.h>

#include <inttypes.h>

typedef struct cast_key_st {
    unsigned int data[32];
    int short_key;
} CAST_KEY;

extern CAST_KEY *key;
extern unsigned int k[32];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16; i++) {
        key->data[2 * i] = k[i];
        if (i > 0) {
            key->data[2 * i - 1] = (k[i + 15] + 16) & 31;
        }
    }
    // Handle last dependency explicitly to preserve correctness
    key->data[31] = (k[31] + 16) & 31;
}
