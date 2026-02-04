#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (in = 0; in < ((255 + 1) / 16); in++, out++) {
        if (in > 5) {
            continue;
        }
        table[in] = out;
        table[-in] = -out;
    }
}
