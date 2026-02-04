#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_out = out;
    for (; in < ((255 + 1) / 16) * 3; in++) {
        table[in] = local_out;
        table[-in] = -local_out;
        local_out += (in & 1) ? 0 : 1;
    }
    out = local_out;
}
