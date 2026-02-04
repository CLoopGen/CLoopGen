#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = (255 + 1) / 16;
    for (in = 0; in < limit && (-in) >= -limit; in++, out++) {
        table[in] = out;
        if (in != 0) {  // Avoid duplicate write at index 0 due to symmetry
            table[-in] = -out;
        }
    }
}
