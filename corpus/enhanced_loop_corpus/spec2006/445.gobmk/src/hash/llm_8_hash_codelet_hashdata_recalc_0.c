#include <stdio.h>

#include <inttypes.h>

typedef unsigned long Hashvalue;

typedef struct {
    Hashvalue hashval[1];
} Hash_data;

extern Hash_data *target;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < (64 / (8 * sizeof(long))); i++) {
        target->hashval[i] = 0;
        for (j = 0; j < 3; j++) {
            target->hashval[i] += j;
        }
    }
}
