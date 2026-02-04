#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; in <= 511; in += 4) {
    table[in] = out;
    table[in + 1] = out ^ 1;
    table[in + 2] = out + 2;
    table[in + 3] = out ^ 3;
    table[-in] = -out;
    table[-(in + 1)] = -out ^ 1;
    table[-(in + 2)] = -out - 2;
    table[-(in + 3)] = -out ^ 3;
}
}
