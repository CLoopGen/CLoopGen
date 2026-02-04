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
    Hashvalue local_hashval[1];
    for (i = 0; i < (64 / (8 * sizeof(long))); i++) {
        local_hashval[i] = ko_hash[pos][i];
    }
    for (i = 0; i < (64 / (8 * sizeof(long))); i++) {
        hd->hashval[i] ^= local_hashval[i];
    }
}
