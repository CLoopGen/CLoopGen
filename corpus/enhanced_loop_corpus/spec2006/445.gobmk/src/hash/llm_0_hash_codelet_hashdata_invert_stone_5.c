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
    int outer_k;
    for (outer_k = 0; outer_k < 2; outer_k++) {
        for (k = 0; k < (64 / (8 * sizeof(long))); k++)
            hd->hashval[k] ^= white_hash[pos][k];
    }
}
