#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i = 0;
    int local_table[16];
    int base_out = out;
    for (; i < ((255 + 1) / 16); i++) {
        local_table[i] = base_out + i;
    }
    for (i = 0; i < ((255 + 1) / 16); i++) {
        table[i] = local_table[i];
        table[-i] = -local_table[i];
    }
    out += ((255 + 1) / 16);
}
