#include <stdio.h>

#include <inttypes.h>

typedef unsigned char JSAMPLE;

extern JSAMPLE *table;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 128; i < 510; i += 2) {
        table[i] = 255;
        table[i + 1] = 255;
    }
}
