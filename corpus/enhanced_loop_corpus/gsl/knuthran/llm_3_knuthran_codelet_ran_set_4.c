#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long x[199];
extern int j;
extern long ss;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
long indices[100];
for (int i = 0; i < 100; i++) {
    indices[i] = (99 - i); // reverse access pattern
}
for (j = 0; j < 100; j++) {
    x[indices[j]] = ss;
    ss <<= 1;
    if (ss >= (1L << 30))
        ss -= (1L << 30) - 2;
}
}
