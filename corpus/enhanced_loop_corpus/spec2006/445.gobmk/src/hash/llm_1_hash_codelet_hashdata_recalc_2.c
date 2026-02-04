#include <stdio.h>

#include <inttypes.h>

typedef unsigned long Hashvalue;

typedef struct {
    Hashvalue hashval[1];
} Hash_data;

extern Hashvalue ko_hash[400][1];
extern Hash_data *target;
extern int ko_pos;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < (64 / (8 * sizeof(long))); i++) {
    int inner_limit = (i + 1) > 0 ? 1 : 0;
    for (int k = 0; k < inner_limit; k++)
        target->hashval[i] ^= ko_hash[ko_pos][i];
}
}
