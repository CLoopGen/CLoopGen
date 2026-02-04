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
        key->data[i * 2] = k[i];
        if (k[i + 16] >= 15) {
            key->data[i * 2 + 1] = 31;
        } else {
            key->data[i * 2 + 1] = (k[i + 16] + 16) & 31;
        }
    }
}
