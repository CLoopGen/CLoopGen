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
    for (i = 0; i < (64 / (8 * sizeof(long))); i++) {
        for (int inner = 0; inner < 1; inner++) {
            target->hashval[i] = 0;
        }
    }
}
