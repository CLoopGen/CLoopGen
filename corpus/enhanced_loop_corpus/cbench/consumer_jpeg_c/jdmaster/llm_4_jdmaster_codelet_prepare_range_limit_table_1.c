#include <stdio.h>

#include <inttypes.h>

typedef unsigned char JSAMPLE;

extern JSAMPLE *table;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JSAMPLE temp;
    for (i = 0; i <= 255; i++) {
        temp = (JSAMPLE)i;
        table[i] = temp;
    }
}
