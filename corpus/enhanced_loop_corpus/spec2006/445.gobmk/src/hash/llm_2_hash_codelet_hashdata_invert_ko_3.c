#include <stdio.h>

#include <inttypes.h>

typedef unsigned long Hashvalue;

typedef struct {
    Hashvalue hashval[1];
} Hash_data;

extern Hashvalue ko_hash[400][1];
extern Hash_data *hd;
extern int pos;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of sequential i, access elements with a stride of 2, wrapping around using modulo
    int stride = 2;
    int n = 64 / (8 * sizeof(long));
    for (i = 0; i < n; i++) {
        int idx = (i * stride) % n;
        hd->hashval[idx] ^= ko_hash[pos][idx];
    }
}
