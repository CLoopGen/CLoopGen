#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_offset = 0;
    int base_out = out;
    for (; in < ((255 + 1) / 16) * 3; in++) {
        if (!(in & 1)) {
            local_offset++;
        }
        table[in] = base_out + local_offset;
        table[-in] = -(base_out + local_offset);
    }
    out = base_out + local_offset;
}
