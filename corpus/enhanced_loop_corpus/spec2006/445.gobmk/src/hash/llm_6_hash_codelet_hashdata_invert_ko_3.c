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
    Hashvalue temp = 0;
    for (i = 0; i < (64 / (8 * sizeof(long))); i++) {
        temp ^= ko_hash[pos][i];
        hd->hashval[i] = temp;
    }
}
