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
    for (i = 0; i < (128 / (8 * sizeof(long))); i += 2) {
        target->hashval[i % 1] = 0;
        if (i + 1 < (64 / (8 * sizeof(long)))) {
            target->hashval[i + 1] = 0;
        }
    }
}
