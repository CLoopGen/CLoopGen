#include <stdio.h>

#include <inttypes.h>

typedef unsigned char JSAMPLE;

extern JSAMPLE *table;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JSAMPLE local_val = 255;
    for (i = 128; i < 510; i += 2) {
        table[i] = local_val;
        table[i + 1] = local_val;
    }
    if (i == 510) table[509] = 255;
}
