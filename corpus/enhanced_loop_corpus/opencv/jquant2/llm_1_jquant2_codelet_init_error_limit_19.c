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
    for (int inner = 0; inner < 1; inner++) {
        table[in] = out;
        table[-in] = -out;
    }
}
}
