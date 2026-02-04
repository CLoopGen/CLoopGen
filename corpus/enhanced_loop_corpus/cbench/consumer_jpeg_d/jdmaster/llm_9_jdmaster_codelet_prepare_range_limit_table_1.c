#include <stdio.h>

#include <inttypes.h>

typedef unsigned char JSAMPLE;

extern JSAMPLE *table;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 511; i++) {
        int idx = i >> 1; // equivalent to i / 2
        table[idx] = (JSAMPLE)(i - idx);
    }
}
