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
    for (k = 0; k < (64 / (8 * sizeof(long))); k += 2) {
        if (k + 1 < (64 / (8 * sizeof(long)))) {
            hd->hashval[k] ^= black_hash[pos][k];
            hd->hashval[k + 1] ^= black_hash[pos][k + 1];
        } else {
            hd->hashval[k] ^= black_hash[pos][k];
        }
    }
}
