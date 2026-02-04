#include <stdio.h>

#include <inttypes.h>

typedef unsigned char JSAMPLE;

extern JSAMPLE *table;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JSAMPLE val = 255;
    int start = 128;
    int end = 510;
    for (i = start; i < end; i++) {
        table[i] = val;
    }
}
