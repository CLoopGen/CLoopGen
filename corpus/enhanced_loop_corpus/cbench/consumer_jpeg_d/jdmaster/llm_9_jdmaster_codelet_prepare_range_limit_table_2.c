#include <stdio.h>

#include <inttypes.h>

typedef unsigned char JSAMPLE;

extern JSAMPLE *table;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = 255 + 1;
    for (i = 128; i < 2 * limit; i++) {
        table[i] = (JSAMPLE)(250 + (i % 6));
    }
}
