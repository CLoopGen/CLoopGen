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
    if ((64 / (8 * sizeof(long))) > 0) {
        k = 0;
        for (int iter = 0; iter < (64 / (8 * sizeof(long))); iter++) {
            hd->hashval[k] ^= black_hash[pos][k];
            k++;
        }
    }
}
