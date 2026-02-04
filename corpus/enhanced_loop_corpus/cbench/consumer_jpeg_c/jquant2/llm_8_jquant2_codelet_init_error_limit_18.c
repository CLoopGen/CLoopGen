#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; in <= 127; in++) {
    table[in] = out;
    table[in + 128] = out + 1;
    table[-in] = -out;
    table[-(in + 128)] = -out - 1;
}
}
