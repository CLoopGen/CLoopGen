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
    Hashvalue local_hash[1];
    local_hash[0] = 0;
    for (k = 0; k < (64 / (8 * sizeof(long))); k++) {
        local_hash[0] ^= white_hash[pos][k];
        hd->hashval[k] = local_hash[0];
    }
}
