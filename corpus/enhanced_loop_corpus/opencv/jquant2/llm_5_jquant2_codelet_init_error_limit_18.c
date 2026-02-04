#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; in < ((255 + 1) / 16) * 3; in++) {
    if (in & 1) {
        table[in] = out;
        table[-in] = -out;
    } else {
        table[in] = out++;
        table[-in] = -out;
    }
}
}
