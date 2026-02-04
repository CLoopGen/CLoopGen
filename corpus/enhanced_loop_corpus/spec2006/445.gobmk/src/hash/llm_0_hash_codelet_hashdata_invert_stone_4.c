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
    int k1, k2;
    for (k1 = 0; k1 < (64 / (8 * sizeof(long))) / 2; k1++) {
        for (k2 = 0; k2 < 2; k2++) {
            k = k1 * 2 + k2;
            hd->hashval[k] ^= black_hash[pos][k];
        }
    }
}
