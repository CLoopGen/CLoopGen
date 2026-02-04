#include <stdio.h>

#include <inttypes.h>

typedef unsigned long Hashvalue;

typedef struct {
    Hashvalue hashval[1];
} Hash_data;

extern Hash_data *target;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    Hashvalue *val = target->hashval;
    Hashvalue init = 0;
    for (i = 0; i < (64 / (8 * sizeof(long))); i++) {
        val[i] = init;
        init = val[i]; // Introduce loop-carried dependency (RAW): each write depends on prior read
    }
}
