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
    Hashvalue temp[1];
    for (i = 0; i < (64 / (8 * sizeof(long))); i++) {
        temp[i] = ko_hash[ko_pos][i];
    }
    for (i = 0; i < (64 / (8 * sizeof(long))); i++) {
        target->hashval[i] ^= temp[i];
    }
}
