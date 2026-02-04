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
    // Variant 1: Strided Memory Access Pattern
    // Instead of sequential k-index access, use a stride of 2 with bounds check
    int stride = 2;
    int limit = 64 / (8 * sizeof(long));
    for (int k = 0; k < limit; k += stride) {
        hd->hashval[k] ^= black_hash[pos][k];
        // Handle remaining element if stride skips the last one
        if (k + 1 < limit) {
            hd->hashval[k + 1] ^= black_hash[pos][k + 1];
        }
    }
}
