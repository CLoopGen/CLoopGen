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
    int limit = (32 / (8 * sizeof(long)));
    for (i = 0; i < limit; i += 2) {
        if (i + 1 < limit) {
            hd->hashval[i] ^= ko_hash[pos][i];
            hd->hashval[i+1] ^= ko_hash[pos][i+1];
        } else {
            hd->hashval[i] ^= ko_hash[pos][i];
        }
    }
}
