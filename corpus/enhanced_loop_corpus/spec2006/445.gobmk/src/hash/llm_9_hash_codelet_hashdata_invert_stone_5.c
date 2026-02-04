#include <stdio.h>

#include <inttypes.h>

typedef unsigned long Hashvalue;

typedef struct {
    Hashvalue hashval[1];
} Hash_data;

extern Hashvalue white_hash[400][1];
extern Hash_data *hd;
extern int pos;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < (32 / (8 * sizeof(long))); k += 2) {
        if (k + 1 < (32 / (8 * sizeof(long)))) {
            hd->hashval[k] ^= white_hash[pos][k];
            hd->hashval[k + 1] ^= white_hash[pos][k + 1];
        } else {
            hd->hashval[k] ^= white_hash[pos][k];
        }
    }
}
