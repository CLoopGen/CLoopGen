#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; in <= 255; in += 2) {
    table[in] = out + 1;
    table[in + 1] = out - 1;
    table[-in] = -out + 1;
    table[-in - 1] = -out - 1;
}
}
