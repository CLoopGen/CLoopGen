#include <stdio.h>

#include <inttypes.h>

typedef unsigned long Hashvalue;

typedef struct {
    Hashvalue hashval[1];
} Hash_data;

extern Hashvalue black_hash[400][1];
extern Hash_data *hd;
extern int pos;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    Hashvalue local_hash[8]; // Assuming max of 64/(8*sizeof(long)) <= 8
    int i;
    for (i = 0; i < (64 / (8 * sizeof(long))); i++) {
        local_hash[i] = black_hash[pos][i];
    }
    for (k = 0; k < (64 / (8 * sizeof(long))); k++) {
        hd->hashval[k] ^= local_hash[k];
    }
}
