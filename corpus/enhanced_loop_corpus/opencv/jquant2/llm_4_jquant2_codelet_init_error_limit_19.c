#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; in <= 255; in++) {
        if (in == 0) continue;
        table[in] = out;
        table[-in] = -out;
    }
}
