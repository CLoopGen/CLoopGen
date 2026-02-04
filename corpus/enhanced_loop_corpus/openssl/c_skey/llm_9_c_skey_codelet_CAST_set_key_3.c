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
    for (i = 0; i < 8; i++) {
        key->data[i * 4]     = k[i * 2];
        key->data[i * 4 + 1] = ((k[i * 2 + 16]) + 16) & 31;
        key->data[i * 4 + 2] = k[i * 2 + 1];
        key->data[i * 4 + 3] = ((k[i * 2 + 17]) + 16) & 31;
    }
}
