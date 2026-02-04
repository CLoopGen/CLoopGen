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
    // Variant 2: Reverse Sequential Access Pattern
    // Traverse the array from last element to first (reverse consecutive access)
    int n = 64 / (8 * sizeof(long));
    for (int i = n - 1; i >= 0; i--) {
        target->hashval[i] ^= ko_hash[ko_pos][i];
    }
}
