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
    // Variant 2: Reverse Sequential Access Pattern
    // Access array elements from high to low index (reverse traversal)
    int n = 64 / (8 * sizeof(long));
    for (int k = n - 1; k >= 0; k--) {
        hd->hashval[k] ^= black_hash[pos][k];
    }
}
