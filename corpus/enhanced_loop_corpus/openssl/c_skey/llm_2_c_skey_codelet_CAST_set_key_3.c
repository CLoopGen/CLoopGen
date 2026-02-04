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
    // Variant 1: Consecutive memory access pattern
    // Reorganize the original strided access into two sequential loops for better spatial locality
    for (i = 0; i < 16; i++) {
        key->data[i] = k[i];  // First 16 elements filled consecutively
    }
    for (i = 0; i < 16; i++) {
        key->data[16 + i] = (k[i + 16] + 16) & 31;  // Next 16 elements filled consecutively
    }
}
