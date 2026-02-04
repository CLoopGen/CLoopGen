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
    int i;
    for (i = 0; i < (64 / (8 * sizeof(long))) * 2; i++) {
        int k = i % (64 / (8 * sizeof(long)));
        hd->hashval[k] ^= white_hash[pos][k];
        hd->hashval[k] += 1;
    }
}
