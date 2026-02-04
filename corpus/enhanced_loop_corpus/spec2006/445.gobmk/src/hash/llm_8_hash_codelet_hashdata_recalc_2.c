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
    int limit = 64 / (8 * sizeof(long));
    for (i = 0; i < limit; i += 2) {
        if (i + 1 < limit) {
            target->hashval[i] ^= ko_hash[ko_pos][i];
            target->hashval[i + 1] ^= ko_hash[ko_pos][i + 1];
        } else {
            target->hashval[i] ^= ko_hash[ko_pos][i];
        }
    }
}
